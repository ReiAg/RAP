#include "headers/AudioPlayer.h"

AudioPlayer::AudioPlayer(){
    auto player_controls = CreatePlayerControls();
    auto DisplayInfo = CreateDisplayInfo();
    addLayout(DisplayInfo, 0, 0, Qt::AlignLeft);
    addLayout(player_controls, 0, 1, Qt::AlignCenter);
    setColumnMinimumWidth(0, 200);
    setColumnMinimumWidth(1, 200);
    setColumnMinimumWidth(2, 200);
    initPlayer();

}

void AudioPlayer::play(){
    player->play();
}
void AudioPlayer::stop(){
    player->stop();
}
void AudioPlayer::setVolume(float value){
    audioOutput->setVolume(value);
}
bool AudioPlayer::isPlaying(){
    return player->isPlaying();
}

bool AudioPlayer::isSourceSet(){
    return !player->source().isEmpty();
};



QVBoxLayout* AudioPlayer::CreatePlayerControls(){
    QVBoxLayout *player_controls = new QVBoxLayout();
    QHBoxLayout *play_back_controls = new QHBoxLayout();
    QHBoxLayout *time_controls = new QHBoxLayout();

    BackButton *back_button = new BackButton(this);
    PlayButton *play_button = new PlayButton(this);
    ForwardButton *forward_button = new ForwardButton(this); 
    QPushButton *loop_button = new QPushButton("Loop");
    QPushButton *mix_button = new QPushButton("Mix");
    //QSlider *time_slider = new QSlider(Qt::Horizontal);
    TimeSlider *time_slider = new TimeSlider();
    QLabel *current_time_label = new QLabel("0:00"), *total_time_label = new QLabel("99:99");

    play_back_controls->addWidget(back_button);
    play_back_controls->addWidget(play_button);
    play_back_controls->addWidget(forward_button);
    play_back_controls->addWidget(loop_button);
    play_back_controls->addWidget(mix_button);
    
    time_controls->addWidget(current_time_label);
    time_controls->addWidget(time_slider);
    time_controls->addWidget(total_time_label);

    player_controls->addLayout(play_back_controls);
    player_controls->addLayout(time_controls);

    return player_controls;
}
QHBoxLayout* AudioPlayer::CreateDisplayInfo(){
    QHBoxLayout *display_info_layout = new QHBoxLayout();
    QVBoxLayout *name_layout = new QVBoxLayout();
    ImageLabel *thumbnail = new ImageLabel("/home/reia/Pictures/__mostima_arknights_drawn_by_naijiaer__a0d7722f1965e4c3341fb43f4bb0d420.jpg");
    name_layout->addWidget(new QLabel("PLACEHOLDER"));
    name_layout->addWidget(new QLabel("Placeholder"));
    display_info_layout->addWidget(thumbnail);
    display_info_layout->addLayout(name_layout);
    return display_info_layout;
}
