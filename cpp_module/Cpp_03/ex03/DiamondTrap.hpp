#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string _name;

	public:
		DiamondTrap();
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& c);
		~DiamondTrap();
		DiamondTrap& operator=(const DiamondTrap& c);
		void attack(const std::string& target);
		void whoAmI(void);
		std::string getName();
		void monitor(void);
};