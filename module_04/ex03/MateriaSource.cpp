#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		_templates[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other._templates[i] != 0)
			_templates[i] = other._templates[i]->clone();
		else
			_templates[i] = 0;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i)
		{
			delete _templates[i];
			if (other._templates[i] != 0)
				_templates[i] = other._templates[i]->clone();
			else
				_templates[i] = 0;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		delete _templates[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (m == 0)
		return;
	for (int i = 0; i < 4; ++i)
	{
		if (_templates[i] == 0)
		{
			_templates[i] = m->clone();
			delete m;
			return;
		}
	}
	delete m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_templates[i] != 0 && _templates[i]->getType() == type)
			return _templates[i]->clone();
	}
	return 0;
}
