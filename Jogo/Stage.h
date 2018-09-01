#ifndef STAGE_H
#define STAGE_H


class Stage
{
public:
    Stage();
    ~Stage();
    void update();
    int getLevelNumber();
private:
    int level;
};

#endif // STAGE_H
