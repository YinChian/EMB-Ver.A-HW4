#include <gui/playscreen_screen/playscreenView.hpp>

playscreenView::playscreenView()
{

}

void playscreenView::setupScreen()
{
    playscreenViewBase::setupScreen();
    
    isStarted = true;

    flexButton1.setTouchable(false);

    // 亂數抽選
    const int selection[32] = { 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 6, 6, 6, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13, 13, 13, 13 };
    
    srand((unsigned int)time(NULL));
    bool label[32] = { false };
    for (int i = 0; i < 32; i++) {
        int n;
        do {
            n = rand() % 32;
        } while (label[n] != 0);
        label[n] = true;
        
        chess[i % 8][i / 8].setColor((int)(selection[n] / 7));
        chess[i % 8][i / 8].setType(6 - selection[n] % 7);
        chess[i % 8][i / 8].assignButton(button[i % 8][i / 8]);
        touchgfx_printf("N = %2d, selection = %2d @ %d, %d, button is at %p\n", n, selection[n], i % 8, i / 8, button[(int)(i / 8)][(i % 8)]);
    }
}

void playscreenView::tearDownScreen()
{
    playscreenViewBase::tearDownScreen();
}

void playscreenView::DiedChesses()
{
    isShowingDeath = true;
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 4; y++) {
            backup[x][y].color = chess[x][y].getColor();
            backup[x][y].type = chess[x][y].getType();
            chess[x][y].setEmpty();
            chess[x][y]._chess->setTouchable(false);
            if (y < 2) chess[x][y].setColor(Red);
            else chess[x][y].setColor(Black);
        }
    }
    flexButton1.setTouchable(true);
    flexButton1.setVisible(true);
    for (int i = 0; i < 16; i++) {
        Type red = died_rem.died_rem[0][i];
        Type black = died_rem.died_rem[1][i];
        
        chess[i % 8][i / 8].setType(red);
        chess[i % 8][i / 8].showPicture();
        chess[i % 8][i / 8 + 2].setType(black);
        chess[i % 8][i / 8 + 2].showPicture();
    }
}

void playscreenView::touchHandle(int y, int x)
{
    switch (chess[x][y].getState())
    {
    case Covered:
        if (!isSecondClicked) {

            // 判斷棋子是誰的，並且換邊
            if (isStarted) {
                side = (chess[x][y].getColor() == Red) ? 0 : 1;
                isStarted = false;
            }
            side = !side;

            chess[x][y].showPicture();
            chess[x][y].setState(UnCovered);
            touchgfx_printf("\nUnCovered! pos = %d, %d", x, y);
        }   
        break;
    case UnCovered:
        if (!isSecondClicked) { // 選棋
            if (side != (chess[x][y].getColor() == Red) ? 0 : 1) return;
            chess[x][y].setState(Selected);
            isSecondClicked = true;
            last.setLastChess(&chess[x][y], x, y);
            
            touchgfx_printf("\nSelected! pos = %d, %d", x, y);
        }
        else {
            // 吃棋子
            if (isGood(x, y)) { 
                // 回合結束 -> 接下來點到的再也不是第二個點到的旗子了(歸零)
                isSecondClicked = false;

                // 新增死亡紀錄
                died_rem.add_died(chess[x][y].getColor(), chess[x][y].getType());

                // 檢查死亡數量
                if (died_rem.died_pointer[static_cast<int>(chess[x][y].getColor())] == 16) {
                    presenter->setWinner(chess[x][y].getColor() == Red ? 1 : 0);
                    application().gotoGameOverScreenNoTransition();
                }

                //換邊
                side = !side;

                //讓前一個棋子消失->移動
                last.chess->setEmpty();
                last.chess->setState(Disappear);

                //轉移資料到新棋子上
                chess[x][y].setColor(last.chess->getColor());
                chess[x][y].setType(last.chess->getType());

                //啟用新棋子
                chess[x][y].setState(UnCovered);

                //顯示新棋子
                chess[x][y].showPicture();
            }
            else { // 換棋子閃爍
                if (side != (chess[x][y].getColor() == Red) ? 0 : 1) return;
                chess[x][y].setState(Selected);
                last.chess->setState(UnCovered);
                last.chess->makeItAppearAgain();
                last.setLastChess(&chess[x][y], x, y);
                touchgfx_printf("\nChange Blink! pos = %d, %d", x, y);
            }
            
        }
        break;
    case Selected: // 取消選取棋子
        chess[x][y].setState(UnCovered);
        chess[x][y].makeItAppearAgain();
        isSecondClicked = false;
        touchgfx_printf("\nSelected -> UnCovered! pos = %d, %d", x, y);
        break;
    case Disappear: // 棋子不存在->做移動
        touchgfx_printf("\nDissapeared! pos = %d, %d", x, y);
        if (isSecondClicked && isGoodtoMove(x, y)) {
            isSecondClicked = false;

            // 換邊
            side = !side;

            //讓前一個位置消失
            last.chess->setEmpty();
            last.chess->setState(Disappear);

            //轉移資料
            chess[x][y].setColor(last.chess->getColor());
            chess[x][y].setType(last.chess->getType());
            
            //啟用新棋子
            chess[x][y].setState(UnCovered);

            //顯示新棋子
            chess[x][y].showPicture();
        }
        break;
    default:
        touchgfx_printf("\ndefault!");
        break;
    }
}

bool playscreenView::isGood(int x, int y)
{
    int last_x  = 0,last_y = 0;
    last.getPosition(last_x, last_y);

    //touchgfx_printf("\n判斷： 前一顆棋子：pos = %d, %d; type = %d, color = %d; 後一顆棋子：pos = %d, %d; type = %d, color = %d\n", last_x, last_y, last.chess->getType(), );

    if (chess[x][y].getColor() == last.chess->getColor()) {
        return false;
    }

    if (
        (
            ((last_x - x == 1 || last_x - x == -1) && last_y == y) ||
            ((last_y - y == 1 || last_y - y == -1) && last_x == x)
        ) &&
        (static_cast<int>(last.chess->getType()) >= static_cast<int>(chess[x][y].getType())||
         last.chess->getType() == Soldier && chess[x][y].getType() == General
            ) &&
        !(last.chess->getType() == General && chess[x][y].getType() == Soldier)
    ) {
        return true;
    }

    
    if (last.chess->getType() == Cannon) {
        if (last_y == y) {
            int chess_count = 0;
            for (int i = x; i != last_x; (last_x > x) ? i++ : i--) {
                if (chess[i][y].getState() == UnCovered) chess_count++;
            }
            return chess_count == 2;
        }
        else if (last_x == x) {
            int chess_count = 0;
            for (int i = y; i != last_y; (last_y > y) ? i++ : i--) {
                if (chess[x][i].getState() == UnCovered) chess_count++;
            }
            return chess_count == 2;
        }
    }

    return false;
}

bool playscreenView::isGoodtoMove(int x, int y)
{
    int last_x = 0, last_y = 0;
    last.getPosition(last_x, last_y);
    if (
        ((last_x - x == 1 || last_x - x == -1) && last_y == y) ||
        ((last_y - y == 1 || last_y - y == -1) && last_x == x)
        ) {
        return true;
    }
    return false;
}

/*
* Virtual Action Handlers
*/

void playscreenView::blink()
{
    if (isSecondClicked && !isShowingDeath) {
        // 如果會卡，請修改這段程式(我還沒有優化)
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 4; y++) {
                // 有棋子是位於被選擇的狀態時
                if (chess[x][y].getState() == Selected) {
                    // 如果是亮的
                    if (chess[x][y].getVisibleStatus() == true) {
                        // 就讓它變暗
                        chess[x][y].setEmpty();
                    }
                    else {
                        // 否則就讓它變亮
                        chess[x][y].makeItAppearAgain();
                    }
                }
            }
        }
    }
}

void playscreenView::TouchScreen() {
    //flexButton1.setVisible(false);
    flexButton1.setTouchable(false);
    isShowingDeath = false;
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 4; y++) {
            chess[x][y].color = backup[x][y].color;
            chess[x][y].type = backup[x][y].type;
            switch (chess[x][y].getState())
            {
            case Covered:
                chess[x][y]._chess->setAlpha(255);
                chess[x][y]._chess->setBitmaps(BITMAP_BLUE_BUTTONS_ROUND_ICON_BUTTON_ID, BITMAP_BLUE_BUTTONS_ROUND_ICON_BUTTON_PRESSED_ID);
                chess[x][y]._chess->invalidate();
                break;
            case UnCovered:case Selected:
                chess[x][y].showPicture();
                break;
            case Disappear:
                chess[x][y].setEmpty();
                break;
            default:
                break;
            }
            chess[x][y]._chess->setTouchable(true);
;        }
    }
}

void playscreenView::b1_1_click()
{
    // Override and implement this function in playscreen
    touchHandle(0, 0);
}

void playscreenView::b1_2_click()
{
    // Override and implement this function in playscreen
    touchHandle(0, 1);
}

void playscreenView::b1_3_click()
{
    // Override and implement this function in playscreen
    touchHandle(0, 2);
}


void playscreenView::b1_4_click()
{
    // Override and implement this function in playscreen
    touchHandle(0, 3);
}

void playscreenView::b1_5_click()
{
    // Override and implement this function in playscreen
    touchHandle(0, 4);
}

void playscreenView::b1_6_click()
{
    // Override and implement this function in playscreen
    touchHandle(0, 5);
}

void playscreenView::b1_7_click()
{
    // Override and implement this function in playscreen
    touchHandle(0, 6);
}

void playscreenView::b1_8_click()
{
    // Override and implement this function in playscreen
    touchHandle(0, 7);
}

void playscreenView::b2_1_click()
{
    // Override and implement this function in playscreen
    touchHandle(1, 0);
}

void playscreenView::b2_2_click()
{
    // Override and implement this function in playscreen
    touchHandle(1, 1);
}

void playscreenView::b2_3_click()
{
    // Override and implement this function in playscreen
    touchHandle(1, 2);
}

void playscreenView::b2_4_click()
{
    // Override and implement this function in playscreen
    touchHandle(1, 3);
}

void playscreenView::b2_5_click()
{
    // Override and implement this function in playscreen
    touchHandle(1, 4);
}

void playscreenView::b2_6_click()
{
    // Override and implement this function in playscreen
    touchHandle(1, 5);
}

void playscreenView::b2_7_click()
{
    // Override and implement this function in playscreen
    touchHandle(1, 6);
}

void playscreenView::b2_8_click()
{
    // Override and implement this function in playscreen
    touchHandle(1, 7);
}

void playscreenView::b3_1_click()
{
    // Override and implement this function in playscreen
    touchHandle(2, 0);
}

void playscreenView::b3_2_click()
{
    // Override and implement this function in playscreen
    touchHandle(2, 1);
}

void playscreenView::b3_3_click()
{
    // Override and implement this function in playscreen
    touchHandle(2, 2);
}

void playscreenView::b3_4_click()
{
    // Override and implement this function in playscreen
    touchHandle(2, 3);
}

void playscreenView::b3_5_click()
{
    // Override and implement this function in playscreen
    touchHandle(2, 4);
}

void playscreenView::b3_6_click()
{
    // Override and implement this function in playscreen
    touchHandle(2, 5);
}

void playscreenView::b3_7_click()
{
    // Override and implement this function in playscreen
    touchHandle(2, 6);
}

void playscreenView::b3_8_click()
{
    // Override and implement this function in playscreen
    touchHandle(2, 7);
}

void playscreenView::trasfer_screen()
{
    application().gotoGameOverScreenNoTransition();
}

void playscreenView::send_winner(bool winner)
{
    presenter->setWinner(winner);
}

void playscreenView::b4_1_click()
{
    // Override and implement this function in playscreen
    touchHandle(3, 0);
}

void playscreenView::b4_2_click()
{
    // Override and implement this function in playscreen
    touchHandle(3, 1);
}

void playscreenView::b4_3_click()
{
    // Override and implement this function in playscreen
    touchHandle(3, 2);
}

void playscreenView::b4_4_click()
{
    // Override and implement this function in playscreen
    touchHandle(3, 3);
}

void playscreenView::b4_5_click()
{
    // Override and implement this function in playscreen
    touchHandle(3, 4);
}

void playscreenView::b4_6_click()
{
    // Override and implement this function in playscreen
    touchHandle(3, 5);
}

void playscreenView::b4_7_click()
{
    // Override and implement this function in playscreen
    touchHandle(3, 6);
}

void playscreenView::b4_8_click()
{
    // Override and implement this function in playscreen
    touchHandle(3, 7);
}




void playscreenView::Chess::assignButton(touchgfx::Button* __chess)
{
    _chess = __chess;
}

// 傳入棋子的Color, Type後，即可設定棋子
void playscreenView::Chess::setPicture(Color color, Type type)
{
    if (type == Null) return;

    // 指定每張圖片對應到的棋子
    const uint16_t picture[2][7] = {
        // Red
        {BITMAP_RP_ID, BITMAP_RC_ID, BITMAP_RR_ID ,BITMAP_RN_ID ,BITMAP_RB_ID ,BITMAP_RA_ID ,BITMAP_RK_ID }, 
        // Black
        {BITMAP_BP_ID, BITMAP_BC_ID, BITMAP_BR_ID ,BITMAP_BN_ID ,BITMAP_BB_ID ,BITMAP_BA_ID ,BITMAP_BK_ID}  
    };

    //設定圖片
    makeItAppearAgain(); // 讓圖片再度顯示->怕原本的是消失的
    touchgfx_printf("\ncolor = %d, pic = %d", static_cast<int>(color), static_cast<int>(type));
    _chess->setBitmaps(picture[static_cast<int>(color)][static_cast<int>(type)], picture[static_cast<int>(color)][static_cast<int>(type)]);
    _chess->invalidate();
}

void playscreenView::Chess::showPicture()
{
    setPicture(color, type);
}

void playscreenView::Chess::setEmpty()
{
    //_chess->setVisible(false);
    _chess->setAlpha(0);
    _chess->invalidate();
}

void playscreenView::Chess::makeItAppearAgain()
{
    _chess->setAlpha(255);
    _chess->invalidate();
}

void playscreenView::Chess::setType(int _type)
{
    type = static_cast<Type>(_type);
}

Type playscreenView::Chess::getType()
{
    return type;
}

void playscreenView::Chess::setColor(int _color)
{
    color = static_cast<Color>(_color);
}

Color playscreenView::Chess::getColor()
{
    return color;
}

void playscreenView::Chess::setState(State _state)
{
    state = _state;
}

bool playscreenView::Chess::getVisibleStatus()
{
    return (_chess->getAlpha() == 255) ? true : false;
}

State playscreenView::Chess::getState()
{
    return state;
}

void playscreenView::Last::setLastChess(Chess* _chess, int _x , int _y)
{
    chess = _chess;
    setPosition(_x, _y);
}

void playscreenView::Last::setPosition(int _x, int _y)
{
    x = _x;
    y = _y;
}

void playscreenView::Last::getPosition(int &_x, int &_y)
{
    _x = x;
    _y = y;
}

void playscreenView::Died_Rem::add_died(Color _color, Type _type)
{
    int* ptr = &died_pointer[static_cast<int>(_color)];
    died_rem[static_cast<int>(_color)][(*ptr)++] = _type;
}

