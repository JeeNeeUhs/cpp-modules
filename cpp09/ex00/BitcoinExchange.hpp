#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>

class BitcoinExchange {
	private:
		std::map<std::string, float> db;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange(const std::string& file);

		BitcoinExchange& operator=(const BitcoinExchange& other);

		~BitcoinExchange();

		void insertDatabase(std::string file);
		void calculateBalance(std::string file);
};

#endif
