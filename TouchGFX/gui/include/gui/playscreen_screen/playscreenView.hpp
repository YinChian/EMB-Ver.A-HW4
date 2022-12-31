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

    // �H�Ѫ���
    class Chess
    {
    public:

        // �N����t�����s�A�Ω��l�ơC
        void assignButton(touchgfx::Button* __chess);

        // �]�w�Ϥ�
        void setPicture(Color color, Type type);

        // ��ܹϤ�
        void showPicture();

        // ���ùϤ�
        void setEmpty();

        // ��_���
        void makeItAppearAgain();

        //�]�w���شѤl
        void setType(int _type);
        //���o�Ѥl
        Type getType();

        //�]�w�C��
        void setColor(int _color);
        //���o�C��
        Color getColor();

        //�]�w���A
        void setState(State _state);
        //���o���A�A��^State
        State getState();

        bool getVisibleStatus();

        // �Ѥl������ (�ϥ�-> ���N .)
        touchgfx::Button* _chess = nullptr;

        // �Ѥl����
        Type type = Null;

        // �Ѥl�C��
        Color color = Red;

        // �Ѥl�����A
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
    
    // �Ѥl�}�C [X][Y]
    Chess chess[8][4];

    // �W�@�ӴѤl
    Last last;

    // ���s�B�z�� (x, y)
    void touchHandle(int x, int y);

    // �P�_�Ѥl�O�_�X�z
    bool isGood(int x, int y);

    // �P�_�O�_�i�H����
    bool isGoodtoMove(int x, int y);

    // �e���O�_�����L��L���s
    bool isSecondClicked = false;

    // �O�_���}��
    bool isStarted = false;

    // �O���䪺��
    bool side = false;

    //�O���O�b�˵����̩O�H
    bool isShowingDeath = false;

    

    Basic_mem backup[8][4];
    Died_Rem died_rem;

    /*
     * ������ƳB�z
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
