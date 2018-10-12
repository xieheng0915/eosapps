#pragma once

#include "../eos/contracts/eosiolib/eosio.hpp"
#include "../eos/contracts/eosiolib/print.hpp"

using namespace eosio;

class Hello : public eosio::contract {

public:
  using contract::contract;

  void hi (account_name user ) {
    printf("Hello，", name{user});
  }
};
EOSIO_ABI( Hello, (hi))
