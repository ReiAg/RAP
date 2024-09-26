#include <QSlider>
#include <QMouseEvent>
class TimeSlider : public QSlider{
    public:
        TimeSlider(){
            //setStyleSheet("QSlider::groove:horizontal {height: 4px; background-color: #363636; border: 0 solid #424242; border-radius: 2px; padding:0 8 0 8;}\n");
            setStyleSheet("QSlider::groove:horizontal {height: 4px; background-color: #363636; border: 0 solid #424242; border-radius: 2px; padding:0 8 0 8;}\n"
                          "QSlider::sub-page:horizontal { background: green; border: 0 solid #424242; border-radius: 2px;}\n"   // Color of the filled part (before the handle)
                          "QSlider::add-page:horizontal { background: #404040; border: 0 solid #424242; border-radius: 2px;}\n" // Color of the empty part (after the handle)
                          "QSlider::handle:horizontal {background-color: #00000000;  margin: -4px -6px -4px -6px;  border: 0 solid black; border-radius: 5;}");
            setSingleStep(1);
            setTracking(true);
            setOrientation(Qt::Horizontal);
            setTickInterval(1);
            setMouseTracking(true);

        }
    protected:
        void enterEvent(QEnterEvent* event) override{
            setStyleSheet("QSlider::groove:horizontal {height: 4px; background-color: #363636; border: 0 solid #424242; border-radius: 2px; padding:0 8 0 8;}\n"
                          "QSlider::sub-page:horizontal { background: green; border: 0 solid #424242; border-radius: 2px;}\n"   // Color of the filled part (before the handle)
                          "QSlider::add-page:horizontal { background: #404040; border: 0 solid #424242; border-radius: 2px;}\n" // Color of the empty part (after the handle)
                          "QSlider::handle:horizontal {background-color: aqua;  margin: -4px -6px -4px -6px;  border: 0 solid black; border-radius: 5;}\n");
            QSlider::enterEvent(event);
        }   
        void leaveEvent(QEvent* event) override{
            setStyleSheet("QSlider::groove:horizontal { height: 4px; background: #363636; }"
                          "QSlider::sub-page:horizontal { background: green; border: 0 solid #424242; border-radius: 2px;}"   // Color of the filled part (before the handle)
                          "QSlider::add-page:horizontal { background: #404040; border: 0 solid #424242; border-radius: 2px;}" // Color of the empty part (after the handle)
                          "QSlider::handle:horizontal {background-color: #00000000;  margin: -4px -6px -4px -6px;  border: 0 solid black; border-radius: 5;}\n");
            QSlider::leaveEvent(event);

        }

        void mouseMoveEvent(QMouseEvent* event) override{
            if(event->buttons() & Qt::LeftButton){
                int slider_position = (maximum() - minimum()) * event->pos().x()/width() + minimum();
                setValue(slider_position);
            }
            else event->ignore();
        }
        void mousePressEvent(QMouseEvent* event) override{
                        //QSlider::mousePressEvent(event);
            event->accept();
            int slider_position = (maximum() - minimum()) * event->pos().x()/width() + minimum();
            setValue(slider_position);
        }

        void mouseReleaseEvent(QMouseEvent* event) override{
            event->ignore();
        }
    };

