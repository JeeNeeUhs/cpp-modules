/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 21:11:38 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/02 14:01:35 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	
	for (int i = 1; i < argc; ++i)
	{
		for (char *c = argv[i]; *c; ++c)
			*c = std::toupper(*c);
		std::cout << argv[i];
	}
	
	std::cout << std::endl;
	return 0;
}