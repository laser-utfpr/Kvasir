#include "strategy.hpp"

/**
    Strategy::updateField(void)

    Updates the field using the FieldLoader class.

    @author Lucca Rawlyk
    @version 2017.10.17-1
*/

void Strategy::updateField(void)
{
    FieldLoader *loader = FieldLoader::getInstance();
    current_field = loader->updateField();
}
