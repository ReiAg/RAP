#include <QWidget>
#include <QGridLayout>
#include <qnamespace.h>
#include "Config.h"
#include "AudioPlayer.h"
class PlayerWindow : public QWidget{
public:
    PlayerWindow(){
        setWindowTitle(PROJECT_NAME);
        setMinimumSize(320,200);
        resize(800,450);
        QGridLayout *main_layout = new QGridLayout();
        AudioPlayer *audio_player = new AudioPlayer();
        main_layout->addLayout(audio_player, 0, 0, Qt::AlignBottom);
        setLayout(main_layout);
        show();
    }
};
