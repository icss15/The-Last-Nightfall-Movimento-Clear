#include "Manager.h"



Manager::Manager()
{
	janela = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "TOE: The Last Nightfall");
	p1.m_texture.loadFromFile("BG_Menu_1280x720.png");
	p1.m_sprite.setTexture(p1.m_texture);

	p1.m_BallTexture.loadFromFile("Escolha_Menu.png");
	p1.m_Ball.setTexture(p1.m_BallTexture);
	p1.m_Ball.setPosition(395, 270);

	GO.m_GameOverScreen.loadFromFile("GameOver.png");
	GO.m_GameOver.setTexture(GO.m_GameOverScreen);
	GO.m_GameOver.setPosition(225, 100);

	j.m_JogoScreen.loadFromFile("Jogo.png");
	j.m_Jogo.setTexture(j.m_JogoScreen);
	j.m_Jogo.setPosition(225, 50);

	j.m_playerTexture.loadFromFile("Player.png");
	j.m_player.setTexture(j.m_playerTexture);
	j.m_player.setPosition(225, 50);


	j.m_ayoTexture.loadFromFile("Ayo.jpg");
	j.m_ayo.setTexture(j.m_ayoTexture);
	j.m_ayo.setPosition(225, 50);

	j.m_inimigoTexture.loadFromFile("inimigo.png");
	j.m_inimigo.setTexture(j.m_inimigoTexture);
	j.m_inimigo.setPosition(500, 50);

	j.m_LeftTexture.loadFromFile("Left.jpg");
	j.m_Left.setTexture(j.m_LeftTexture);
	j.m_Left.setPosition(1000, 50);

	j.m_RightTexture.loadFromFile("Right.jpg");
	j.m_Right.setTexture(j.m_RightTexture);
	j.m_Right.setPosition(500, 50);

	j.m_arrowTexture.loadFromFile("Arrow.png");
	j.m_arrow.setTexture(j.m_arrowTexture);



}


Manager::~Manager()
{
	delete janela;
}

void Manager::Programa()
{
	while (Quit == false)
	{
		Inputs();
		Update();
		Render();
	}
}

void Manager::Inputs()
{
	while (janela->pollEvent(eventos))
	{
		posicaoMouse = sf::Mouse::getPosition(*janela);
		switch (eventos.type)
		{
		case sf::Event::Closed:
			Quit = true;
			break;
		case sf::Event::KeyPressed:
			InputTeclado();
			break;
		case sf::Event::MouseButtonPressed:
			MouseClicado();
			break;
		case sf::Event::MouseMoved:
			MouseMovido();
			break;
		}
	}
}

void Manager::Update()
{
	switch (EstadoTela)
	{
	case MENU:
		UpdateMenu();
		break;
		
	case JOGO:
		UpdateJogo();
		break;

	case GAMEOVER:
		UpdateGameOver();
		break;
	}
}

void Manager::Render()
{
	janela->clear();
	switch (EstadoTela)
	{
	case MENU:
		RenderMenu();
		break;

	case JOGO:
		RenderJogo();
		break;

	case GAMEOVER:
		RenderGameOver();
		break;
	case QUIT: 
		Quit = true;
		break;
	}
	janela->display();
}

void Manager::UpdateMenu()
{

	

}

void Manager::UpdateJogo()
{

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		j.m_arrow.setPosition(sf::Mouse::getPosition().x- 388, sf::Mouse::getPosition().y- 250);

	}

	if (j.m_inimigo.getGlobalBounds().intersects(j.m_player.getGlobalBounds())) // Floor
	{
		j.m_player.setPosition(j.m_inimigo.getPosition().x - j.m_player.getPosition().x, j.m_inimigo.getPosition().y - j.m_player.getPosition().y);
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		j.m_player.move(0,-0.1);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		j.m_player.move(0, 0.3);
	

		j.m_playerTexture.loadFromFile("giphy.gif");
		j.m_player.setTexture(j.m_playerTexture);
			
	
	
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		j.m_player.move(-0.1, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		j.m_player.move(0.1, 0);
	}

	
		j.m_ayo.setPosition(sf::Mouse::getPosition().x-388, sf::Mouse::getPosition().y-250);
		
		if (j.m_player.getPosition().x <= 0) {//Left
			j.m_player.setPosition(0.f, j.m_player.getPosition().y);
			if (j.m_player.getPosition().x >= SCREEN_WIDTH - j.m_player.getGlobalBounds().width) //Right
				j.m_player.setPosition(SCREEN_WIDTH - j.m_player.getGlobalBounds().width, j.m_player.getPosition().y);
			if (j.m_player.getPosition().y <= 0) //Top
				j.m_player.setPosition(j.m_player.getPosition().x, 0.f);
			if (j.m_player.getPosition().y >= SCREEN_HEIGHT - j.m_player.getGlobalBounds().height) //Bottom
				j.m_player.setPosition(j.m_player.getPosition().x, SCREEN_HEIGHT - j.m_player.getGlobalBounds().height);
		}
		if (j.m_arrow.getPosition().x <= 0) //Left
			j.m_arrow.setPosition(0.f, j.m_arrow.getPosition().y);
		if (j.m_arrow.getPosition().x >= SCREEN_WIDTH - j.m_arrow.getGlobalBounds().width) //Right
			j.m_arrow.setPosition(SCREEN_WIDTH - j.m_arrow.getGlobalBounds().width, j.m_arrow.getPosition().y); 
		if (j.m_arrow.getPosition().y <= 0) //Top
			j.m_arrow.setPosition(j.m_player.getPosition().x, 0.f);
		if (j.m_arrow.getPosition().y >= SCREEN_HEIGHT - j.m_arrow.getGlobalBounds().height) //Bottom
			j.m_arrow.setPosition(j.m_arrow.getPosition().x, SCREEN_HEIGHT - j.m_arrow.getGlobalBounds().height);

}

void Manager::UpdateGameOver()
{
}

void Manager::RenderMenu()
{
	janela->draw(p1.m_sprite);

	texto1.setFillColor(sf::Color::White);
	
	janela->draw(p1.m_Ball);
}

void Manager::RenderJogo()
{
	janela->draw(j.m_Jogo);

	janela->draw(j.m_player);

	janela->draw(j.m_ayo);

	janela->draw(j.m_inimigo);

	janela->draw(j.m_Left);

	janela->draw(j.m_Right);

	janela->draw(j.m_arrow);
}

void Manager::RenderGameOver()
{
	janela->draw(GO.m_GameOver);
}

void Manager::InputTeclado() {
	P_Menu = &Menu_Op;
	switch (eventos.key.code) {
		case sf::Keyboard::Up:
			switch (Menu_Op) {
			case 0:
				break;
			case 1:
				*P_Menu = 0;
				p1.m_Ball.setPosition(395, 270);
				OpcaoMenu = 1;
				//EstadoTela = JOGO;
				break;
			case 2:
				*P_Menu = 1;
				p1.m_Ball.setPosition(395, 360);
				OpcaoMenu = 2;
				//EstadoTela = OPÇÕES;

				break;
			case 3:
				*P_Menu = 2;
				p1.m_Ball.setPosition(395, 450);
				OpcaoMenu = 3;
				//EstadoTela = GAME OVER;
				break;
			}
			break;

		case sf::Keyboard::Down:
			switch (Menu_Op) {
			case 0:
				*P_Menu = 1;
				p1.m_Ball.setPosition(395, 360);
				OpcaoMenu = 2;
				//EstadoTela = OPÇÕES;
				break;
			case 1:
				*P_Menu = 2;
				p1.m_Ball.setPosition(395, 450);
				OpcaoMenu = 3;
				//EstadoTela = GAME OVER;
				break;
			case 2:
				*P_Menu = 3;
				p1.m_Ball.setPosition(395, 530);
				OpcaoMenu = 4;
				//EstadoTela = SAIR;
				break;
			}
			break;

	case sf::Keyboard::Escape:
		Quit = true;
		break;

	case sf::Keyboard::Return:
		if (OpcaoMenu == JOGO)
			EstadoTela = JOGO;
		else if (OpcaoMenu == GAMEOVER)
			EstadoTela = GAMEOVER;
		else if (OpcaoMenu == QUIT)
			EstadoTela = QUIT;
		break;
	}
}


void Manager::MouseClicado()
{
	switch (eventos.mouseButton.button)
	{
	case sf::Mouse::Left: //Mouse Botao Esquerdo Pressionado


		break;

	case sf::Mouse::Right: //Mouse Botao Direito Pressionado
		break;
	}
}

void Manager::MouseMovido() {
	switch (eventos.MouseMoved)
	{

	}
}
