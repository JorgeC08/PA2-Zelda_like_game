#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(30);
	ofSetWindowTitle("Finding Pollitos");
	setupAreas();
	// Declaration and Initialization of States
	player = new Player(100, 6);
	titleState = new TitleState();
	overworldState = new OverworldState(player, currentArea);
	battleState = new BattleState(player, currentArea);
	bossBattleState = new BossBattleState(player, currentArea);
	winState = new WinState();
	endGameState = new EndGameState();

	pauseState = new PauseState();
	loadingState = new LoadingState();

	// Initial State
	currentState = titleState;
}

//--------------------------------------------------------------
void ofApp::setupAreas()
{
	//each area is 672 pixels wide and 640 pixels high, with 10 and 8 pixels of space between the player and the edge of the map respectively
	//each in-game pixel is 4 * 1 screen pixel
	Boss *boss1 = new Boss("33", 30, 6, "enemy2", 4 * 120, 4 * 342, 2);
	Boss *boss2 = new Boss("44", 30, 6, "enemy1", 4 * 120, 4 * 342, 2);
	vector<StaticEntity *> palos;
	StaticEntity *palo1 = new StaticEntity(1000, 2000, 150, 200, "images/entities/palos/palo1.png");
	StaticEntity *palo2 = new StaticEntity(2000, 1000, 150, 200, "images/entities/palos/palo6.png");
	StaticEntity *palo3 = new StaticEntity(2500, 2000, 150, 200, "images/entities/palos/palo7.png");
	StaticEntity *palo4 = new StaticEntity(1000, 1000, 150, 200, "images/entities/palos/palo8.png");
	StaticEntity *palo5 = new StaticEntity(2000, 2000, 150, 200, "images/entities/palos/palo7.png");
	StaticEntity *palo6 = new StaticEntity(800, 1450, 150, 200, "images/entities/palos/palo7.png");
	palos.push_back(palo1);
	palos.push_back(palo2);
	palos.push_back(palo3);
	palos.push_back(palo4);
	palos.push_back(palo5);
	palos.push_back(palo6);

	vector<StaticEntity *> palos2;
	StaticEntity *palo1area2 = new StaticEntity(1000, 2000, 150, 200, "images/entities/palos/piedra.png");
	StaticEntity *palo2area2 = new StaticEntity(2000, 1000, 150, 200, "images/entities/palos/piedra1.png");
	StaticEntity *palo3area2 = new StaticEntity(2500, 2000, 150, 200, "images/entities/palos/nieve.png");
	StaticEntity *palo4area2 = new StaticEntity(1000, 1000, 150, 200, "images/entities/palos/nieve1.png");
	StaticEntity *palo5area2 = new StaticEntity(2000, 2000, 150, 200, "images/entities/palos/piedra.png");
	StaticEntity *palo6area2 = new StaticEntity(800, 1450, 150, 200, "images/entities/palos/nieve.png");
	palos2.push_back(palo1area2);
	palos2.push_back(palo2area2);
	palos2.push_back(palo3area2);
	palos2.push_back(palo4area2);
	palos2.push_back(palo5area2);
	palos2.push_back(palo6area2);
	vector<Enemy *> enemies2;
	ofPoint entrancePosition2(4 * 110, 4 * 116);
	Enemy *area2Enemy1 = new Enemy("21", 30, 6, "enemy2", 4 * 120, 4 * 342);
	Enemy *area2Enemy2 = new Enemy("22", 30, 6, "enemy2", 4 * 254, 4 * 130);
	Enemy *area2Enemy3 = new Enemy("23", 30, 6, "enemy2", 4 * 542, 4 * 124);
	Enemy *area2Enemy4 = new Enemy("24", 30, 6, "enemy2", 4 * 532, 4 * 368);
	Enemy *area2Enemy5 = new Enemy("25", 30, 6, "enemy2", 4 * 266, 4 * 312);
	Enemy *area2Enemy6 = new Enemy("26", 30, 6, "enemy2", 4 * 194, 4 * 532);
	enemies2.push_back(area2Enemy1);
	enemies2.push_back(area2Enemy2);
	enemies2.push_back(area2Enemy3);
	enemies2.push_back(area2Enemy4);
	enemies2.push_back(area2Enemy5);
	enemies2.push_back(area2Enemy6);
	vector<Friend *> friends;
	Friend *area1friend = new Friend("05", "friend", 4 * 150, 4 * 300);
	friends.push_back(area1friend);
	area2 = new Area(NULL, "images/areas/area2.png", "audio/ice.wav", "images/stages/stage2.png", entrancePosition2, enemies2, friends, palos2, "|Hoth", boss2);
	vector<Enemy *> enemies1;
	ofPoint entrancePosition1(4 * 414, 4 * 566);
	Enemy *area1Enemy1 = new Enemy("11", 20, 4, "enemy1", 4 * 480, 4 * 432);
	Enemy *area1Enemy2 = new Enemy("12", 20, 4, "enemy1", 4 * 225, 4 * 178);
	Enemy *area1Enemy3 = new Enemy("13", 20, 4, "enemy1", 4 * 420, 4 * 178);
	enemies1.push_back(area1Enemy1);
	enemies1.push_back(area1Enemy2);
	enemies1.push_back(area1Enemy3);
	area1 = new Area(area2, "images/areas/area1.png", "audio/forest.wav", "images/stages/stage1.png", entrancePosition1, enemies1, friends, palos, "|Naboo", boss1);
	currentArea = area1;
}

//--------------------------------------------------------------
void ofApp::update()
{
	if (currentState != nullptr)
	{
		if (!pauseState->getPause() || currentState->getStateName() == "Loading")
			currentState->tick();

		if (currentState->hasFinished())
		{
			currentState->toggleMusic();
			if (currentState->getStateName() != "Loading" && currentState->getStateName() != "Battle" && currentState->getStateName() != "BossBattle")
			{
				loadingState->reset();
				loadingState->setNextState(currentState->getNextState());
				currentState = loadingState;
			}
			else
			{
				if (currentState->getNextState() == "Title")
				{
					endGameState->setWin(false);
					area1->resetEnemies();
					area2->resetEnemies();
					currentArea = area1;
					battleState->resetPlayer();
					battleState->setStage(currentArea->getStage());
					overworldState->loadArea(currentArea);
					currentState = titleState;
				}
				else if (currentState->getNextState() == "Overworld")
				{
					currentState = overworldState;
				}
				else if (currentState->getNextState() == "BossBattle")
				{
					bossBattleState->startBattle(currentArea->getBoss());
					currentState = bossBattleState;
				}
				else if (currentState->getNextState() == "Battle")
				{
					battleState->startBattle(overworldState->getEnemy());
					currentState = battleState;
				}
				else if (currentState->getNextState() == "Win")
				{
					overworldState->getEnemy()->kill();
					if (currentArea->getRemainingEnemies() == 0 && currentArea->getBoss()->getisDefeated() && !currentArea->getBoss()->getisActive()) // boss is defeated and deactivated
					{
						if (currentArea->getNextArea() == NULL)
						{
							endGameState->setWin(true);
							currentState = endGameState;
						}
						else
						{
							currentArea = currentArea->getNextArea();
							overworldState->loadArea(currentArea);
							battleState->setStage(currentArea->getStage());
							currentState = winState;
						}
					}
					else
					{
						currentState = winState;
					}
				}
				else if (currentState->getNextState() == "End"){
					currentState = endGameState;
				}

				currentState->toggleMusic();
				currentState->reset();
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	if (currentState != nullptr)
	{
		currentState->render();

		pauseState->render();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (currentState != nullptr)
	{
		currentState->keyPressed(key);

		if (currentState == overworldState || currentState == battleState)
			pauseState->keyPressed(key);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
	if (currentState != nullptr)
		currentState->keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
	if (currentState != nullptr)
		currentState->mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
	if (currentState != nullptr)
		currentState->mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	if (currentState != nullptr)
		currentState->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
	if (currentState != nullptr)
		currentState->mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
	if (currentState != nullptr)
		currentState->mouseEntered(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
	if (currentState != nullptr)
		currentState->mouseExited(x, y);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
	if (currentState != nullptr)
		currentState->windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
	if (currentState != nullptr)
		currentState->gotMessage(msg);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
	if (currentState != nullptr)
		currentState->dragEvent(dragInfo);
}