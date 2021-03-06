#include "CameraPowerController.h"
#include "ProductVariant.h"

namespace
{
ProductVariant getProductVariant()
{
#if __linux__
    return ProductVariant::A;
#else
    return ProductVariant::B;
#endif
}
} // namespace

int main()
{
    CameraPowerController cameraPowerController{getProductVariant()};
    cameraPowerController.turnOnCamera();
    cameraPowerController.turnOffCamera();

    return 0;
}
