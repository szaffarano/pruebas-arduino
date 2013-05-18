#include <LiquidCrystal.h>

#include <MenuEntry.h>
#include <LCDDisplay.h>
#include <MenuManager.h>
#include <MenuEntry.h>

#define UP 65
#define DOWN 66
#define SELECT 32
#define BACK 68

const int LCDD7 = 7;
const int LCDD6 = 6;
const int LCDD5 = 5;
const int LCDD4 = 4;
const int LCDE  = 3;
const int LCDRS = 2;

MenuManager* mm;
Display* display;
MenuEntry* bla;

void setup() {
	Serial.begin(9600);
	setupMenu();
	delay(500);
	display->print("inicializando...");
	display->clear();
	display->print("renderizando...");
	delay(500);
	mm->draw();
}

void loop() {
	askUser();
}

static void setupMenu() {	
	display = new LCDDisplay(LCDRS, LCDE, LCDD4, LCDD5, LCDD6, LCDD7, 16, 2);
	display->print("inicializando...");
	delay(500);

	mm = new MenuManager(display);
	
	MenuEntry* menu = 
	 		  (new MenuEntry("Reloj"))
				->addChild(new MenuEntry("Hora"))
				->addChild(new MenuEntry("Configurar", showTime, mm))
		->add((new MenuEntry("Temporizador"))
				->addChild(new MenuEntry("Configurar"))
				->addChild(new MenuEntry("Iniciar"))
		)
		->add((new MenuEntry("Alarma"))
				->addChild(new MenuEntry("Seteo"))
				->addChild(new MenuEntry("Iniciar"))
		);
	
	mm->setMenu(menu);
	mm->draw();

	display->clear();
	display->print("inicializado!");
}

static void askUser() {
	char pressed = 0;
	
	if (Serial.available() > 0) {
		pressed = Serial.read();
	}
	switch (pressed) {
	case UP:
		Serial.println("UP");
		mm->up();
		mm->draw();
		break;
	case DOWN:
		Serial.println("DOWN");
		mm->down();
		mm->draw();
		break;
	case SELECT:
		Serial.println("SELECT");
		mm->select();
		mm->draw();
		break;
	case BACK:
		Serial.println("BACK");
		mm->back();
		mm->draw();
		break;
	}
}

void showTime(void* data) {
	MenuManager* m = ((MenuManager*)data);
	m->getDisplay()->clear();
	m->getDisplay()->setCursor(0, 0);
	m->getDisplay()->print("que hora?");
	delay(2000);
}
