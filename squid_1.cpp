#include <bangtal>
#include <Timer.h>
#include <windows.h>
using namespace bangtal;

int main()
{

	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

	//���� ����
	auto endgame = Scene::create("GameOver", "Images/��.png"); //���� Ŭ��� ������ ȭ��
	auto giveup = Scene::create("���� ����", "Images/giveup.png"); //������ �ߵ� ������ ȭ��
	auto scene1 = Scene::create("����ȭ��", "Images/���.png"); //����ȭ��
	auto startButton = Object::create("Images/start.png", scene1, 590, 70);
	auto endButton = Object::create("Images/end.png", scene1, 590, 20);
	//����1
	auto scene2 = Scene::create("1������", "Images/���2.png"); //����1 ���
	auto nextlevel_1 = Object::create("Images/nextlevel_1.png", scene2, 250, 110, false);
	auto nextlevel_2 = Object::create("Images/nextlevel_2.png", scene2, 643, 110, false);
	//����2
	auto game2s = Scene::create("2������", "Images/���3.png"); //����2 ���
	auto game2 = Scene::create("2������", "Images/���3.png"); //����2 ���
	auto game2_2 = Scene::create("2������", "Images/���3.png"); //����2 ���
	auto game2_3 = Scene::create("2������", "Images/���3.png"); //����2 ���
	//����3
	auto game3s = Scene::create("3������", "Images/���4.png"); //����3 ���
	auto game3 = Scene::create("3������", "Images/���5.png"); //����3 ���
	//����
	auto Final_s = Scene::create("����", "Images/Endding.png"); //���� ���



	//����ȭ��
	endButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		endgame->enter();
		return true;
		});

	startButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene2->enter();
		return true;
		});

	//ù��° ���� 
	auto killer = Object::create("Images/����.png", scene2, 1025, 73);
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
			showMessage("1�ܰ� ���");
		}

		nextlevel_1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			game2s->enter(); //����2�� ����
			showMessage("�̹� ������ ��ȭ �����Դϴ�.");
			return true;
			});
		nextlevel_2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			giveup->enter(); //�ߵ�����
			return true;
			});

		return true;
	});

	timer1->setOnTimerCallback([&](TimerPtr timer)->bool {
		endButton->show();
		showMessage("�ð��ʰ� Ż��!");
		endgame->enter();
		return true;
		});


	//�ι�° ���� : ����
	auto startgame2 = Object::create("Images/start2.png", game2s, 400, 110);
	startgame2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		game2->enter(); //����2�� ����
		showMessage("�� ����� �̸��� �ٴϿ� ũ���̱��̴�.");
		return true;
		});
	
	
	auto quiz1 = Object::create("Images/quiz1.png", game2, 300, 73); //1������ �׸�
	auto quiz2 = Object::create("Images/quiz2.png", game2_2, 450, 73); //2������ �׸�
	

	//1������
	auto O_button = Object::create("Images/O.png", game2, 450, 10);
	O_button->setScale(.5f);
	auto X_button = Object::create("Images/X.png", game2, 643, 10);
	X_button->setScale(.5f);

	O_button->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		game2_2->enter(); //2�� ����
		showMessage("�� ����� �̸��� �ٴϿ� ����Ŭ�����̴�.");
		return true;
		});
	X_button->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		endgame->enter(); //Ż��
		return true;
		});
	//2������
	auto O_button2 = Object::create("Images/O.png", game2_2, 450, 10);
	O_button2->setScale(.5f);
	auto X_button2 = Object::create("Images/X.png", game2_2, 643, 10);
	X_button2->setScale(.5f);
	O_button2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		game2_3->enter(); //3�� ����
		showMessage("��ȭ '007'�� �⿬���� �ƴ� ����� ���ÿ�.");
		return true;
		});
	X_button2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		endgame->enter(); //Ż��
		return true;
		});

	//3������, ����
	auto q1 = Object::create("Images/q1.png", game2_3, 200, 220);
	auto q2 = Object::create("Images/q2.png", game2_3, 450, 220);
	auto q3 = Object::create("Images/q3.png", game2_3, 700, 220);
	auto q4 = Object::create("Images/q4.png", game2_3, 950, 220);

	q1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		endgame->enter(); //Ż��
		return true;
		});
	q2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		endgame->enter(); //Ż��
		return true;
		});
	q3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		game3s->enter(); //���� ���� ����
		showMessage("������ ���ӱ��� �Ͻǰ̴ϱ�?");
		return true;
		});
	q4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		endgame->enter(); //Ż��
		return true;
		});


	//����° ���� : Ȧ¦
	auto nextlevel_a = Object::create("Images/nextlevel_1.png", game3s, 250, 110);
	auto nextlevel_b = Object::create("Images/nextlevel_2.png", game3s, 643, 110);
	nextlevel_a->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		game3->enter(); //������ ����		
		return true;
		});
	nextlevel_b->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		giveup->enter(); //�ߵ�����
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
			showMessage("����� ������� �־����ϱ�?");
			showKeypad("0007", Final);
			return true;
			});
		
		return true;
		});


	Final->setOnKeypadCallback([&](ObjectPtr object)->bool {
		Final_s->enter();
		showMessage("���ϵ帳�ϴ�. ��� ���ӿ� ����ϼ̽��ϴ�.");
		auto restart = Object::create("Images/restart.png", Final_s, 750, 400);
		auto endding = Object::create("Images/endding_button.png", Final_s, 950, 400);
		restart->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			scene1->enter(); //�ٽý���
			return true;
			});

		endding->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
			endGame();
			return true;
			});

		return true;
		});





	startGame(scene1);

	return 0;
}