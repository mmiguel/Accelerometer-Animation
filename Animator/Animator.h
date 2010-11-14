/*
 * Defines a class for Group 2's EE180D free form animation widget
 *
 *
 *
 */
#ifndef ANIMATOR_H
#define ANIMATOR_H
#include <QCoin.h>
#include <Inventor/nodes/SoRotation.h>
#include <Inventor/engines/SoCalculator.h>
#include <Inventor/engines/SoElapsedTime.h>
#include <Inventor/engines/SoComposeRotation.h>
#include <QTableWidget>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QSlider>
#include <QLCDNumber>


/*
 * Angles
 * --------------------------------------
 * Angle 0 = Shoulder Lateral Angle
 * Angle 1 = Shoulder Alateral Angle
 * Angle 2 = Shoulder Rotation Angle
 * Angle 3 = Elbow Bending Angle
 * Angle 4 = Elbow Rotation Angle
 * Angle 5 = Wrist Bending Angle
 */
#define NUM_ANGLES 6
#define NUM_PARAMS 4
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define NUM_TABS 2

class Animator: public QCoin
{
	Q_OBJECT
private:
	SoSeparator* root;
	SoSeparator* body;
	SoSeparator* arm;
	SoRotation* angle[NUM_ANGLES];
	SbVec3f angleAxis[NUM_ANGLES];
	SoCalculator* angleCalc[NUM_ANGLES];
	SoComposeRotation* angleCompRot[NUM_ANGLES];
	SoElapsedTime* time;

	//GUI stuff
	QTabWidget* tabs;
	QWidget* windows[NUM_TABS];
	QTableWidget* tbl;
	QPushButton* goButton;
	QPushButton* fileButton;
	QPushButton* resetButton;
   QTextEdit* txtEdit;
	QSlider* sldAngle[NUM_ANGLES];
	QLCDNumber* lcdAngle[NUM_ANGLES];
	int currentTab;

public:
	Animator(QWidget* parent = 0);
	~Animator();
	void show();
public slots:
	void updateMotion(void);
   void updateWithFile(void);
   void resetParams(void);
   void setAngle0(int);
   void setAngle1(int);
   void setAngle2(int);
   void setAngle3(int);
   void setAngle4(int);
   void setAngle5(int);
	void tabSwitch(int);

signals:

};
#endif