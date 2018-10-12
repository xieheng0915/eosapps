#include "Players.hpp"

namespace Oasis{
    using namespace eosio;
    using std::string;

    class Players : public contract{
      using contract::contract;

    public:
      Players(account_name self):contract(self){}

      //@abi action
      void add(account_name account, string& username){
        require_auth(account);

        playerIndex players(_self, _self);

        auto iterator = players.find(account);
        eosio_assert(iterator==players.end(), "Address for account already exist ");

        players.emplace(account, [&](auto& player){
          player.account_name = account;
          player.username = username;
          player.level = 1;
          player.health_points = 1000;
          player.energy_points = 1000;
        });
      }

      void update(account_name account, uint64_t level, int64_t health_points, int64_t energy_points){
        require_auth(account);

        playerIndex players(_self,_self);

        auto iterator = players.find(account);
        eosio_assert(iterator != players.end(),"Address for account not found.");

        players.modify(iterator,account,[&](auto& player){
            player.level = level;

            if((player.health_points - health_points) < 0){
                player.health_points = 0;
            }else{
                player.health_points -= health_points;
            }
            if((player.energy_points - energy_points) < 0){
                player.energy_points = 0;
            }else{
                player.energy_points -= energy_points;
            }

        });
      }
      void getplayer(const account_name account) {
          /* code */
          playerIndex players(_self,_self);

          auto iterator = players.find(account);
          eosio_assert(iterator != players.end(),"Address for account not found.");

          auto currentPlayer = players.get(account);
          print("Username:", currentPlayer.username.c_str()," Level:", currentPlayer.level," HealthPoints:",currentPlayer.health_points," EnergyPoints:",currentPlayer.energy_points);
        }




    private:

        struct player{
          uint64_t account_name;
          string username;
          uint64_t level;
          int64_t health_points = 1000;
          int64_t energy_points = 1000;

          uint64_t primary_key() const {return account_name;}
          EOSLIB_SERIALIZE(player,(account_name)(username)(level)(health_points)(energy_points))

        };

        typedef multi_index<N(player), player> playerIndex;
    };
    EOSIO_ABI(Players,(add)(update)(getplayer))
}
