#include "headers/ImageLabel.h"

ImageLabel::ImageLabel(QString image){
    setImage(image);
}
void ImageLabel::setImage(QString image){
    QPixmap pixmap(image);     
    int w = 64, h = 64;
    QPixmap scaledPixmap = pixmap.scaled(w, h, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    QRect rect((scaledPixmap.width() - w) / 2, (scaledPixmap.height() - h) / 2, w, h);
    QPixmap croppedPixmap = scaledPixmap.copy(rect);
    setPixmap(croppedPixmap);
    resize(croppedPixmap.size());
}
