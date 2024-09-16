#include <QGridLayout>
#include <QMediaPlayer>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSlider>
#include <QLabel>
#include "ImageLabel.h"

class AudioPlayer : public QGridLayout{
public:
    AudioPlayer();
private:
    class TimeSlider : public QSlider{
    public:
        TimeSlider();
    };
    class PlayerButton : public QPushButton{
    public:
        PlayerButton();
    };
    QVBoxLayout* CreatePlayerControls();
    QHBoxLayout* CreateDisplayInfo();
    QMediaPlayer *player = nullptr;
};
