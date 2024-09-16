
#include <QLabel>
#include <QObject>
#include <QPixmap>
class ImageLabel : public QLabel{
public: 
    ImageLabel(QString image);
    void setImage(QString image);
};
