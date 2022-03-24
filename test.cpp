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
    assert(a.isTableEmpty()); // test if craft table is empty
    assert(a.size() == 0); // test if craft table size is 0 because empty

    assert(!a.isTableEmpty()); // should fail

    return 0;
}       