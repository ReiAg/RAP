#include <QGridLayout>
#include <QMediaPlayer>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSlider>
#include <QLabel>
#include <qnamespace.h>
#include "ImageLabel.h"
#include "TimeSlider.h"
class AudioPlayer : public QGridLayout{
public:
    AudioPlayer();
private:
    class PlayerButton : public QPushButton{
    public:
        PlayerButton();
    };
    QVBoxLayout* CreatePlayerControls();
    QHBoxLayout* CreateDisplayInfo();
    QMediaPlayer *player = nullptr;
};
