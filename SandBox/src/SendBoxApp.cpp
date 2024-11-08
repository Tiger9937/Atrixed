#include <Atrixed.h>

class sanbox :public Atrixed::App {

public :
	sanbox() {

	}
	~sanbox() {

	}
};


Atrixed::App* Atrixed::CreatApplication() {
	return new sanbox();
}
