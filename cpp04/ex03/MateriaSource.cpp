#include <iostream>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : count(0) {
	for (int i = 0; i < 4; ++i) {
		materias[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other) : count(other.count) {
	for (int i = 0; i < 4; ++i) {
		if (other.materias[i]) {
			materias[i] = other.materias[i]->clone();
		} else {
			materias[i] = NULL;
		}
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	if (this != &other) {
		for (int i = 0; i < 4; ++i) {
			delete materias[i];
			if (other.materias[i]) {
				materias[i] = other.materias[i]->clone();
			} else {
				materias[i] = NULL;
			}
		}
		count = other.count;
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; ++i) {
		delete materias[i];
	}
}

void MateriaSource::learnMateria(AMateria* materia) {
	if (count < 4 && materia) {
		for (int i = 0; i < 4; ++i) {
			if (!materias[i]) {
				materias[i] = materia;
				count++;
				return;
			}
		}
		std::cout << "Inventory full, cannot learn " << materia->getType() << std::endl;
	} else {
		std::cout << "Invalid materia or inventory full." << std::endl;
	}

}

AMateria* MateriaSource::createMateria(const std::string &type) {
	for (int i = 0; i < 4; ++i) {
		if (materias[i] && materias[i]->getType() == type) {
			return materias[i]->clone();
		}
	}
	std::cout << "Materia of type " << type << " not found." << std::endl;
	return NULL;
}
