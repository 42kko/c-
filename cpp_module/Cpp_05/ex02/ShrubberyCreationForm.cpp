#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137, target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &c)
    : AForm(c)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &c)
{
    if (this == &c)
        return (*this);
    AForm::operator=(c);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute() const
{
	std::fstream fs;
	fs.open(this->getName() + "_shrubbery", std::fstream::out | std::fstream::trunc);
	if (!fs.good())
		std::cerr << "Error while opening Shrubbery target file" << std::endl;

	fs <<
	"              * *\n"
	"           *    *  *\n"
	"      *  *    *     *  *\n"
	"     *     *    *  *    *\n"
	" * *   *    *    *    *   *\n"
	" *     *  *    * * .#  *   *\n"
	" *   *     * #.  .# *   *\n"
	"  *     \"#.  #: #\" * *    *\n"
	" *   * * \"#. ##\"       *\n"
	"   *       \"###\n"
	"             \"##\n"
	"              ##.\n"
	"              .##:\n"
	"              :###\n"
	"              ;###\n"
	"            ,####.\n"
	"/\\/\\/\\/\\/\\/.######.\\/\\/\\/\\/\\\n";

	fs.close();
}