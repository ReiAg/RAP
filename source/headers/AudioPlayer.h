#include <QGridLayout>
#include <QMediaPlayer>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSlider>
#include <QLabel>
#include <QAudioOutput>
#include <qevent.h>
#include <qnamespace.h>
#include "ImageLabel.h"
#include "TimeSlider.h"


class AudioPlayer : public QGridLayout{
public:
    AudioPlayer();
    bool isPlaying();
    bool isSourceSet();
    void play();
    void stop();
    void setVolume(float value);

private:
    void initPlayer(QString src = ""){
        player = new QMediaPlayer();
        audioOutput = new QAudioOutput();
        audioOutput->setVolume(50);
        player->setAudioOutput(audioOutput);
        if(!src.isEmpty()){
            player->setSource(src);
            player->play();
        }
    }

    QVBoxLayout* CreatePlayerControls();
    QHBoxLayout* CreateDisplayInfo();
    QMediaPlayer* player = nullptr;
    QAudioOutput* audioOutput = nullptr;

};

class PlayButton : public ImageLabel{
public:
    PlayButton(AudioPlayer* player){
        audio_player = player;
        setImage(":/icons/play.png", 32, 32);
    }
    AudioPlayer* audio_player = nullptr;
protected:
    void mouseReleaseEvent(QMouseEvent* event) override{
        if(event->button() == Qt::LeftButton){
            event->accept();
            if(audio_player->isPlaying()){
                audio_player->stop();
            }else{
                audio_player->play();   
            }
        }
    }

};
class BackButton : public ImageLabel{
public:
    BackButton(AudioPlayer* player){
        audio_player = player;
        setImage(":/icons/back.png", 32, 32);
    }
    AudioPlayer* audio_player = nullptr;
protected:
    void mouseReleaseEvent(QMouseEvent* event) override{
        if(event->button() == Qt::LeftButton){
            event->accept();
            
        }
    }

};

class ForwardButton : public ImageLabel{
public:
    ForwardButton(AudioPlayer* player){
        audio_player = player;
        setImage(":/icons/forward.png", 32, 32);
    }
    AudioPlayer* audio_player = nullptr;
protected:
    void mouseReleaseEvent(QMouseEvent* event) override{
        if(event->button() == Qt::LeftButton){
            event->accept();
            
        }
    }

};


