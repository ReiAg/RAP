
#include <QLabel>
#include <QObject>
#include <QPixmap>
class ImageLabel : public QLabel{
public: 
    ImageLabel();
    ImageLabel(QString image);
    void setImage(QString image, int w = 64, int h = 64);
};
