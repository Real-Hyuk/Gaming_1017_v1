#include <bangtal>
#include <Timer.h>
#include <windows.h>
using namespace bangtal;

int main()
{

	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

	//시작 세팅
	auto endgame = Scene::create("GameOver", "Images/끝.png"); //게임 클리어에 실패한 화면
	auto giveup = Scene::create("게임 종료", "Images/giveup.png"); //게임을 중도 포기한 화면
	auto scene1 = Scene::create("시작화면", "Images/배경.png"); //메인화면
	auto startButton = Object::create("Images/start.png", scene1, 590, 70);
	auto endButton = Object::create("Images/end.png", scene1, 590, 20);
	//게임1
	auto scene2 = Scene::create("1번게임", "Images/배경2.png"); //게임1 배경
	auto nextlevel_1 = Object::create("Images/nextlevel_1.png", scene2, 250, 110, false);
	auto nextlevel_2 = Object::create("Images/nextlevel_2.png", scene2, 643, 110, false);
	//게임2
	auto game2s = Scene::create("2번게임", "Images/배경3.png"); //게임2 배경
	auto game2 = Scene::create("2번게임", "Images/배경3.png"); //게임2 배경
	auto game2_2 = Scene::create("2번게임", "Images/배경3.png"); //게임2 배경
	auto game2_3 = Scene::create("2번게임", "Images/배경3.png"); //게임2 배경
	//게임3
	auto game3s = Scene::create("3번게임", "Images/배경4.png"); //게임3 배경
	auto game3 = Scene::create("3번게임", "Images/배경5.png"); //게임3 배경
	//엔딩
	auto Final_s = Scene::create("엔딩", "Images/Endding.png"); //엔딩 배경



	//메인화면
	endButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		endgame->enter();
		return true;
		});

	startButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene2->enter();
		return true;
		});

	//첫번째 게임 
	auto killer = Object::create("Images/인형.png", scene2, 1025, 73);
	auto continueButton = Object::create("Images/continue.png", scene2, 1150, 40);
	continueButton->hide();
	auto timer1 = Timer::create(8.f);
	showTimer(timer1);

	int runnerX = 0, runnerY = 500;
	auto runner = Object::create("Images/runner.png", scene2, runnerX, runnerY);
	runner->setScale(.3f);

	runner->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		timer1->start();
		runnerX = runnerX + 30;
		runner->locate(scene2, runnerX, runnerY);


		if (runnerX > 900) {
			//playButton->hide();
			//startButton->setImage("Images/restart.png");
			nextlevel_1->show();
			nextlevel_2->show();
			timer1->stop();
			showMessage("1단계 통과");
		}

		nextlevel_1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			game2s->enter(); //게임2로 진행
			showMessage("이번 게임은 영화 퀴즈입니다.");
			return true;
			});
		nextlevel_2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			giveup->enter(); //중도포기
			return true;
			});

		return true;
	});

	timer1->setOnTimerCallback([&](TimerPtr timer)->bool {
		endButton->show();
		showMessage("시간초과 탈락!");
		endgame->enter();
		return true;
		});


	//두번째 게임 : 퀴즈
	auto startgame2 = Object::create("Images/start2.png", game2s, 400, 110);
	startgame2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		game2->enter(); //게임2로 진행
		showMessage("이 배우의 이름은 다니엘 크레이그이다.");
		return true;
		});
	
	
	auto quiz1 = Object::create("Images/quiz1.png", game2, 300, 73); //1번문제 그림
	auto quiz2 = Object::create("Images/quiz2.png", game2_2, 450, 73); //2번문제 그림
	

	//1번문제
	auto O_button = Object::create("Images/O.png", game2, 450, 10);
	O_button->setScale(.5f);
	auto X_button = Object::create("Images/X.png", game2, 643, 10);
	X_button->setScale(.5f);

	O_button->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		game2_2->enter(); //2번 문제
		showMessage("이 배우의 이름은 다니엘 래드클리프이다.");
		return true;
		});
	X_button->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		endgame->enter(); //탈락
		return true;
		});
	//2번문제
	auto O_button2 = Object::create("Images/O.png", game2_2, 450, 10);
	O_button2->setScale(.5f);
	auto X_button2 = Object::create("Images/X.png", game2_2, 643, 10);
	X_button2->setScale(.5f);
	O_button2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		game2_3->enter(); //3번 문제
		showMessage("영화 '007'의 출연진이 아닌 사람을 고르시오.");
		return true;
		});
	X_button2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		endgame->enter(); //탈락
		return true;
		});

	//3번문제, 고르기
	auto q1 = Object::create("Images/q1.png", game2_3, 200, 220);
	auto q2 = Object::create("Images/q2.png", game2_3, 450, 220);
	auto q3 = Object::create("Images/q3.png", game2_3, 700, 220);
	auto q4 = Object::create("Images/q4.png", game2_3, 950, 220);

	q1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		endgame->enter(); //탈락
		return true;
		});
	q2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		endgame->enter(); //탈락
		return true;
		});
	q3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		game3s->enter(); //다음 게임 진출
		showMessage("마지막 게임까지 하실겁니까?");
		return true;
		});
	q4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		endgame->enter(); //탈락
		return true;
		});


	//세번째 게임 : 홀짝
	auto nextlevel_a = Object::create("Images/nextlevel_1.png", game3s, 250, 110);
	auto nextlevel_b = Object::create("Images/nextlevel_2.png", game3s, 643, 110);
	nextlevel_a->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		game3->enter(); //마지막 게임		
		return true;
		});
	nextlevel_b->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		giveup->enter(); //중도포기
		return true;
		});
	auto start_3 = Object::create("Images/start3.png", game3, 500, 300);
	
	auto timer3 = Timer::create(0.5f);
	auto Final = Object::create("Images/Final.png", game3, 500, 300);

	start_3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		timer3->start();
		start_3->hide();
		//virtual void bangtal::Timer::set(const Second& 0.1);
		auto m1 = Object::create("Images/man.png", game3, 83, 137);
		auto m2 = Object::create("Images/man.png", game3, 574, 201);
		auto m3 = Object::create("Images/man.png", game3, 627, 414);
		auto m4 = Object::create("Images/man.png", game3, 265, 279);
		auto m5 = Object::create("Images/man.png", game3, 423, 394);
		auto m6 = Object::create("Images/man.png", game3, 872, 324);
		auto m7 = Object::create("Images/man.png", game3, 101, 211);
		
		timer3->setOnTimerCallback([&](TimerPtr restartT)->bool {
			m1->hide();
			m2->hide();
			m3->hide();
			m4->hide();
			m5->hide();
			m6->hide();
			m7->hide();
			showMessage("몇명의 사람들이 있었습니까?");
			showKeypad("0007", Final);
			return true;
			});
		
		return true;
		});


	Final->setOnKeypadCallback([&](ObjectPtr object)->bool {
		Final_s->enter();
		showMessage("축하드립니다. 모든 게임에 통과하셨습니다.");
		auto endding = Object::create("Images/endding_button.png", Final_s, 950, 400);
		endding->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			endGame();
			return true;
		});

		return true;
		});





	startGame(scene1);

	return 0;
}
