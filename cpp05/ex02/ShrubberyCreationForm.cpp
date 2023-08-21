/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:57:08 by esilva-s          #+#    #+#             */
/*   Updated: 2023/08/21 23:57:09 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
    this->_target = "default";
    std::cout << "ShrubberyCreationForm Creation Form Default was created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
    this->_target = target;
    std::cout << "ShrubberyCreationForm Creation Form was created" << std::endl;    
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) : AForm("ShrubberyCreationForm", 145, 137)
{
    this->_target = src.getTarget();
    std::cout << "ShrubberyCreationForm was copied" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm was destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	if (this != &rhs)
    {
        std::cout << "ShrubberyCreationForm has been assigned" << std::endl;
        this->_target = rhs.getTarget();
    }
	return *this;
}

std::ostream &operator<<(std::ostream & o, ShrubberyCreationForm const & ref)
{
	o << ref.getName() << ", target is " << ref.getTarget() << ", grade to signed " << ref.getGradeSigned() <<  ", grade to execute " << ref.getGradeExec() << ", is  signed? " << ref.getSigned() <<"." ;
	return o;
}


void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    this->checkExecute(executor);

    std::string file;
    std::ofstream ofs;

    file = this->_target + "_shrubbery";
    ofs.open(file.c_str());                                                                                                                                                                                                                                                                       
    ofs << "                                             ....                         \n";                      
    ofs << "                               . ...  ...:...:..: ::::.                   \n";                      
    ofs << "                             ...::::::..:::...:.:.........                \n";                      
    ofs << "                           .:.::.....::. .:::.:.:..:::.......             \n";                      
    ofs << "                        .:..::::..::..::.^::^::::.:::^:::...:. .:.        \n";                      
    ofs << "                       .:..:.:::::^:::^^::::::::.:...:.::.....::...       \n";                      
    ofs << "                        .::^:^:.:^^:::..:^^:.:::::.:.:^:::::^^::..        \n";                      
    ofs << "                        ..:.:::::::::::.....:::^::::..::..:::::..:.       \n";                      
    ofs << "                        :::.::::::::::^:.:.::.:^^::::.::......::::...     \n";                      
    ofs << "             .::::.   ..::^...: .:^^^:...^:...:^^:::.:^^^^^^:..:. .^.     \n";                      
    ofs << "              ......:.....    . .^^..:...   .: .::^:.::::....      .      \n";                      
    ofs << "             .::..::^::.::. . ..^^..:^^^.   .   .^.:...   .:.             \n";                      
    ofs << "         .....:..::::::...:::..::: .:::.                                  \n";                      
    ofs << "     .. .:...:::..:....::::^.:::::.::.:.                                  \n";                      
    ofs << "    .:..::.::::..:::::.:^^:....::.                                        \n";                      
    ofs << "   .:::^..:::::::::::^^^^:. :.:::.         .    .                         \n";                      
    ofs << "   ..:::::.::.::...:::::  : :..:::         :.:.:.   .::                   \n";                      
    ofs << "    ...::..:.:::..::.      ....:..:.      ..:: :.:..:..... ..  .....      \n";                      
    ofs << "        .....:::.   .   . ..::. ::.:... .   ::..::.....:..:......:.:.     \n";                      
    ofs << "            ..      . .:::..:: .:..:.:.         . ...:.:..:.......::.     \n";                      
    ofs << "             ........:..::::^^^..:.::^^^:..         ..::..:::::::.::::.    \n";                     
    ofs << "          ......::...:::::..::::.:......:::..: ::..   ...::...:.....  .   \n";                      
    ofs << "          ..:::..:......:: .....:... .. ...:...:::. .::...........:.      \n";                      
    ofs << "      ......:::::^^:::. .   ...::..........:...:.::^^^^.:..::::::::.....   .   \n";                 
    ofs << "     .:......  .:.            .::::.::....::..::....::^^^:.........::.:....:   \n";                 
    ofs << "           .    .          .:.::::::::..::.:.:.::.   ::^^^:..:.::...:.:.::.. ....       .   \n";    
    ofs << "                           :::.:....::...:.......       .::...  ...::. :.:...::..........   \n";    
    ofs << "                             ...:...........  :         .^::.        :::::.:::::.....:... . \n";    
    ofs << "                             ......::...                :^^^.            ... ..::^:..:.:..   \n";   
    ofs << "                            ...:.:.:.   .            .::::.                     .::..:....   \n";   
    ofs << "                               .::...              .:^^:^.                       .. ..  .  \n";     
    ofs << "                                   .              ::::^.               \n";                         
    ofs << "                                                ::..:                  \n";                         
    ofs << "                                              :.:::                   \n";                          
    ofs << "                                            .:..:.                     \n";                         
    ofs << "                                           .::::.                      \n";                         
    ofs << "                                          .::.:.                       \n";                         
    ofs << "                                         .^:^::                      \n";                           
    ofs << "                                 ....   .::..:. ..                 \n";                             
    ofs << "                    .....  .... ..:^:::::^:..:..:^.  ............. \n";                             
    ofs << "                  ....:.........:...::......:.:...:........:::..... \n";                            
    ofs << "                  ....:...:...:.:..:::.....:.::...::..:....:::.......\n";                           
    ofs << "                  :::::::::..::::.:::::::::::::.:::::::.:::::::::::.:\n";                           
    ofs << "                     ::::::::::::::::::::::::::::::::::::::::::::::\n";                             
    ofs << "                     :...:.::....:::::::::::::::::::::::::....::::\n";                              
    ofs << "                      :..:........::.:::::....:.:::::.::::....:.:.\n";                              
    ofs << "                      .:::::::::::::::::::::::::::::::::::::::::.\n";                               
    ofs << "                       :::::::::::::::::::::::::::::::::::::::::.\n";                               
    ofs << "                       ::::::::::::::::::::::::::::::::::::::::.\n";                                
    ofs << "                       .:::::::::::::::::::::::::::::::::::::::.\n";                                
    ofs << "                        .:::...:................................\n";                                
    ofs << "                           .......:::::::::::::::::::.....::::.\n";
    ofs.close();                                    
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string ShrubberyCreationForm::getTarget(void) const
{
    return (this->_target);
}

/* ************************************************************************** */