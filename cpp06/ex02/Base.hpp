#ifndef BASE_HPP
#define BASE_HPP

class Base {
	private:
		
	public:
		virtual ~Base() {}

};

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
