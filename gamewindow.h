#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "chess.h"
#include <iostream>
#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QPushButton>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QVector>
#include <QHBoxLayout>
#include <QFont>
#include <QLabel>
using namespace std;

class GameWindow : public QMainWindow
{
    Q_OBJECT

private:
    QGridLayout * GLayout;
//    QGridLayout * Gviewlayout;
    QHBoxLayout * TurnLayout;
//    QHBoxLayout * CloseLayout;
    QLabel * TurnLabel;
    QFont * TurnFont;
    QWidget * GWidget;
    QPushButton * GClose;
    QGraphicsView * GameView;
    QGraphicsScene * GameScene;
    Chess * ChessGame;
    QVector<QVector<QGraphicsRectItem *>> * Squares;

//    vector<vector<QGraphicsRectItem *>> *Squares;


public:
    explicit GameWindow(QWidget *parent = 0);

    void CreateBoard();
    void CreateRow(QBrush first,QBrush last,int y);

    void FirstMoveLevel(BoardPosition * sel);
    void SecondMoveLevel(BoardPosition * sel);

    void MovePicture(Movement & mv);

    void ShowSuggestedPos(QList<BoardPosition> & sl);

    void InsertBeadPictures()
    {
        QImage pawnpic(":/BeadPics/blackpawn.jpg");

        pawnpic = pawnpic.scaled(98,93,Qt::KeepAspectRatio,Qt::FastTransformation);

        QBrush b(pawnpic);

        for(int i = 0 ; i < 8 ; i++)
        {
            Squares->at(1).at(i)->setBrush(b);
        }
    }

signals:

public slots:

    void MoveBead();
    void ResolveCheck();
    void ModifyTurn();
};

#endif // GAMEWINDOW_H
