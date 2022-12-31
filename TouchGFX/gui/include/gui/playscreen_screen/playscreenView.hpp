#ifndef PLAYSCREENVIEW_HPP
#define PLAYSCREENVIEW_HPP

#include <gui_generated/playscreen_screen/playscreenViewBase.hpp>
#include <gui/playscreen_screen/playscreenPresenter.hpp>
#include <touchgfx/Utils.hpp>
#include <BitmapDatabase.hpp>
#include <time.h>
#include <stdlib.h>

// General = 6, Advisor = 5, Elephant = 4, Horse = 3, Chariot = 2, Cannon = 1, Soldier = 0
enum Type { General = 6, Advisor = 5, Elephant = 4, Horse = 3, Chariot = 2, Cannon = 1, Soldier = 0, Null = -1 };

// Red = 0, Black = 1
enum Color { Red = 0, Black = 1 };

// Covered = 0, UnCovered = 1, Selected = 2, Disappear = 3
enum State { Covered, UnCovered, Selected, Disappear };


class playscreenView : public playscreenViewBase
{
public:
    playscreenView();
    virtual ~playscreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    // 象棋物件
    class Chess
    {
    public:

        // 將物件配對到按鈕，用於初始化。
        void assignButton(touchgfx::Button* __chess);

        // 設定圖片
        void setPicture(Color color, Type type);

        // 顯示圖片
        void showPicture();

        // 隱藏圖片
        void setEmpty();

        // 恢復顯示
        void makeItAppearAgain();

        //設定哪種棋子
        void setType(int _type);
        //取得棋子
        Type getType();

        //設定顏色
        void setColor(int _color);
        //取得顏色
        Color getColor();

        //設定狀態
        void setState(State _state);
        //取得狀態，返回State
        State getState();

        bool getVisibleStatus();

        // 棋子的指標 (使用-> 替代 .)
        touchgfx::Button* _chess = nullptr;

        // 棋子類型
        Type type = Null;

        // 棋子顏色
        Color color = Red;

        // 棋子的狀態
        State state = Covered;

    private:

    };

    class Last {
    public:
        void setLastChess(Chess* _chess, int _x, int _y);
        void setPosition(int _x, int _y);
        void getPosition(int& _x, int& _y);
        Chess* chess = nullptr;
    private:
        int x = 0;
        int y = 0;
    };

    class Basic_mem {
    public:
        Type type;
        Color color;
    };

    class Died_Rem
    {
    public:
        void add_died(Color _color, Type _type);
        Type died_rem[2][16] = {
            {Null, Null, Null, Null, Null, Null, Null, Null, Null, Null, Null, Null, Null, Null, Null, Null},
            {Null, Null, Null, Null, Null, Null, Null, Null, Null, Null, Null, Null, Null, Null, Null, Null}
        };
        int died_pointer[2] = { 0 };
    private:
        
    };


    void trasfer_screen();
    void send_winner(bool winner);
protected:
    //const int c[] = { 3,12,0,0,9,9,1,1,10,10,8,8,15,15,6,6,13,13,2,2,11,11,7,7,7,7,7,14,14,14,14,14 };
    touchgfx::Button* button[8][4] = {/*
        {&b1_1, &b1_2, &b1_3, &b1_4, &b1_5, &b1_6, &b1_7, &b1_8},
        {&b1_1_1, &b1_2_1, &b1_3_1,&b1_4_1,&b1_5_1,&b1_6_1,&b1_7_1,&b1_8_1},
        {&b1_1_2, &b1_2_2,&b1_3_2,&b1_4_2,&b1_5_2,&b1_6_2,&b1_7_2,&b1_8_2},
        {&b1_1_5,&b1_2_5,&b1_3_5,&b1_4_5,&b1_5_5,&b1_6_5,&b1_7_5,&b1_8_5}*/
        
        {&b1_1, &b1_1_1, &b1_1_2, &b1_1_5},
        {&b1_2, &b1_2_1, &b1_2_2, &b1_2_5},
        {&b1_3, &b1_3_1, &b1_3_2, &b1_3_5},
        {&b1_4, &b1_4_1, &b1_4_2, &b1_4_5},
        {&b1_5, &b1_5_1, &b1_5_2, &b1_5_5},
        {&b1_6, &b1_6_1, &b1_6_2, &b1_6_5},
        {&b1_7, &b1_7_1, &b1_7_2, &b1_7_5},
        {&b1_8, &b1_8_1, &b1_8_2, &b1_8_5}
    };
    
    // 棋子陣列 [X][Y]
    Chess chess[8][4];

    // 上一個棋子
    Last last;

    // 按鈕處理器 (x, y)
    void touchHandle(int x, int y);

    // 判斷棋子是否合理
    bool isGood(int x, int y);

    // 判斷是否可以移動
    bool isGoodtoMove(int x, int y);

    // 前面是否有按過其他按鈕
    bool isSecondClicked = false;

    // 是否為開局
    bool isStarted = false;

    // 是哪邊的局
    bool side = false;

    //是不是在檢視死者呢？
    bool isShowingDeath = false;

    

    Basic_mem backup[8][4];
    Died_Rem died_rem;

    /*
     * 虛擬函數處理
     * Virtual Action Handlers
     */
    virtual void b1_1_click();
    virtual void b1_2_click();
    virtual void b1_3_click();
    virtual void b1_4_click();
    virtual void b1_5_click();
    virtual void b1_6_click();
    virtual void b1_7_click();
    virtual void b1_8_click();
    virtual void b2_1_click();
    virtual void b2_2_click();
    virtual void b2_3_click();
    virtual void b2_4_click();
    virtual void b2_5_click();
    virtual void b2_6_click();
    virtual void b2_7_click();
    virtual void b2_8_click();
    virtual void b3_1_click();
    virtual void b3_2_click();
    virtual void b3_3_click();
    virtual void b3_4_click();
    virtual void b3_5_click();
    virtual void b3_6_click();
    virtual void b3_7_click();
    virtual void b3_8_click();
    virtual void b4_1_click();
    virtual void b4_2_click();
    virtual void b4_3_click();
    virtual void b4_4_click();
    virtual void b4_5_click();
    virtual void b4_6_click();
    virtual void b4_7_click();
    virtual void b4_8_click();
    virtual void blink();
    virtual void DiedChesses();
    virtual void TouchScreen();
};

#endif // PLAYSCREENVIEW_HPP
