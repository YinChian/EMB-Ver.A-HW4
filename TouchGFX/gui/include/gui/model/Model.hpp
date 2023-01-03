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

    void setSeed(int _seed) {
        seed = _seed;
    }

    int getSeed() {
        return seed;
    }

    void tick();
protected:
    ModelListener* modelListener;
    bool winner_side = false;
    int seed = 0;
};

#endif // MODEL_HPP
