#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << "<input_file>" << std::endl;
        return 1;
    }

        BitcoinExchange btcExchange;
		try{
			btcExchange.loadDatabase("data.csv");
			btcExchange.processTransactions(argv[1]);
		}
		catch (std::exception& e){
			std::cerr << e.what() << std::endl;
		}

    return 0;
}