// Copyright (c) 2008  GeometryFactory Sarl (France).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you may redistribute it under
// the terms of the Q Public License version 1.0.
// See the file LICENSE.QPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.5-branch/GraphicsView/include/CGAL/Qt/GraphicsViewLineInput.h $
// $Id: GraphicsViewLineInput.h 45924 2008-10-01 09:19:53Z afabri $
// 
//
// Author(s)     : Andreas Fabri <Andreas.Fabri@geometryfactory.com>
//                 Laurent Rineau <Laurent.Rineau@geometryfactory.com>

#ifndef CGAL_QT_GRAPHICS_VIEW_LINE_INPUT_H
#define CGAL_QT_GRAPHICS_VIEW_LINE_INPUT_H

#include <QGraphicsView>
#include <QRectF>
#include <QPointF>
#include <QGraphicsItem>
#include <QGraphicsLineItem> 
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>

#include <CGAL/Qt/Converter.h>
#include <CGAL/Qt/GraphicsViewInput.h>
#include <CGAL/Qt/utility.h>

namespace CGAL {
namespace Qt {

template <typename K>
class GraphicsViewLineInput : public GraphicsViewInput
{
public:
  GraphicsViewLineInput(QObject *parent, QGraphicsScene* s);

protected:
    
  virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
  virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
  virtual void keyPressEvent(QKeyEvent *event);
  
  bool eventFilter(QObject *obj, QEvent *event);
  

  

private:

  QRectF boundingRect();
  QLineF qlinef();

  bool second;
  QGraphicsLineItem line;
  QPointF qsp, qtp;
  typename K::Point_2 sp, tp;
  typename K::Line_2 l;
  QGraphicsScene *scene_;  
  Converter<K> convert;
};

template <typename K>
QRectF
LineInput_2<K>::boundingRect()
{
  QRectF rect = CGAL::Qt::viewportsBbox(scene_);
  return rect;
}


template <typename K>
GraphicsViewLineInput<K>::GraphicsViewLineInput(QObject *parent, QGraphicsScene* s)
  : GraphicsViewInput(parent), second(false), scene_(s)
{}


template <typename K>
QLineF
GraphicsViewLineInput<K>::qlinef()
{

  sp = convert(qsp);
  tp = convert(qtp);
  typename K::Line_2  l(sp,tp);
  QRectF qrect(boundingRect());
  typename K::Iso_rectangle_2 rect;
  rect = convert(qrect);
  Object o = intersection(l,rect);
  typename K::Segment_2 s;
  assign(s, o);
  return convert(s);
}

template <typename K>
void 
GraphicsViewLineInput<K>::mousePressEvent(QGraphicsSceneMouseEvent *event)
{  
  if(event->modifiers()  & ::Qt::ShiftModifier){
    return;
  }
  if(second){
      qtp = event->scenePos();
      sp = convert(qsp);
      tp = convert(qtp);
      scene_->removeItem(&line);
      emit generate(CGAL::make_object(typename K::Line_2(sp,tp)));
  } else {
    qsp = event->scenePos();
    qtp = QPointF(qsp.x()+1, qsp.y());
    line.setLine(qlinef());
    scene_->addItem(&line);
  }
  second = !second;
}




template <typename K>
void 
GraphicsViewLineInput<K>::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
  qtp = event->scenePos();
  if(qtp == qsp){
    qtp = QPointF(qsp.x()+1, qsp.y());
  } 
  line.setLine(qlinef());
}


template <typename K>
void 
GraphicsViewLineInput<K>::keyPressEvent ( QKeyEvent * event ) 
{
  if(event->key() != Qt::Key_Delete){
    return;
  }
  if(second){
    scene_->removeItem(&line);
    second = false;
  }
}



template <typename K>
bool 
GraphicsViewLineInput<K>::eventFilter(QObject *obj, QEvent *event)
{
  if (event->type() == QEvent::GraphicsSceneMousePress) {
    QGraphicsSceneMouseEvent *mouseEvent = static_cast<QGraphicsSceneMouseEvent *>(event);
    mousePressEvent(mouseEvent);
    return true;
  } else if (event->type() == QEvent::GraphicsSceneMouseMove) {
    QGraphicsSceneMouseEvent *mouseEvent = static_cast<QGraphicsSceneMouseEvent *>(event);
    mouseMoveEvent(mouseEvent);
    return true;
  } else if (event->type() == QEvent::KeyPress) {
    QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
    keyPressEvent(keyEvent);
    return true;
  } else{
    // standard event processing
    return QObject::eventFilter(obj, event);
  }
} 

} // namespace Qt
} // namespace CGAL

#endif // CGAL_QT_GRAPHICS_VIEW_LINE_INPUT_H
