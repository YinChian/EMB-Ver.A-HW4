#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    bool getWinnerSide() {
        return winner_side;
    }

    void setWinnerSide(bool set) {
        winner_side = set;
    }

    void tick();
protected:
    ModelListener* modelListener;
    bool winner_side = false;
};

#endif // MODEL_HPP
