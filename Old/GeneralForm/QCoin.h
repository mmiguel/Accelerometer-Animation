/*
 * Defines a Qt widget compatible with Coin and SoQt
 *
 *
 *
 */
#ifndef QCOIN_H
#define Q_COIN_H
#include <QWidget>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>
#include <Inventor/SoInput.h>

class QCoin : public QWidget
{
	Q_OBJECT

private:
	SoSeparator* root;
	SoQtExaminerViewer* eViewer;
public:
	QCoin( QWidget* parent = 0);
	QCoin( const char* scene_graph ,QWidget* parent = 0);
   ~QCoin();
   void setRoot(SoSeparator* newRoot);
	void show();
	void viewAll();
};
#endif //QCOIN_H
