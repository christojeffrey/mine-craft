#include "src/CraftTable.hpp"
#include "src/Item.hpp"
#include "src/Tool.hpp"
#include "src/NonTool.hpp"
#include "src/Recipe.hpp"
#include "src/GameState.hpp"
#include "src/Exception.hpp"
#include "src/Inventory.hpp"
#include <assert.h>
#include <bits/stdc++.h>
#include <vector>
#include <list>
#include <sstream>
#include <map>

int main() {
    CraftTable a;
    assert(a.isTableEmpty());
    assert(a.size() == 0);

    return 0;
}       