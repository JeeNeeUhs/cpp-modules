#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria* materias[4];
		int count;

	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);

		MateriaSource &operator=(const MateriaSource &other);

		~MateriaSource();

		void learnMateria(AMateria* materia);
		AMateria* createMateria(const std::string &type);
};

#endif
