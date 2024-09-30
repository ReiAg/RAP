#include "headers/ImageLabel.h"

ImageLabel::ImageLabel(){
};
ImageLabel::ImageLabel(QString image){
    setImage(image);
}
void ImageLabel::setImage(QString image, int w, int h){
    QPixmap pixmap(image);     
    QPixmap scaledPixmap = pixmap.scaled(w, h, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    QRect rect((scaledPixmap.width() - w) / 2, (scaledPixmap.height() - h) / 2, w, h);
    QPixmap croppedPixmap = scaledPixmap.copy(rect);
    setPixmap(croppedPixmap);
    resize(croppedPixmap.size());
}
