#include <stdio.h>
enum marks
{
    Phy = 1,
    Chem = 4,
    Maths,
    Comp
};
int main()
{
    enum marks m;
    m = Maths;
    printf("%d ", Chem);
    switch (m)
    {
    case Phy:
        printf("Physics");
        break;
    case Chem:
        printf("Chemistry");
        break;
    case Maths:
        printf("Maths");
        break;
    case Comp:
        printf("Computers");
        break;
    }
    printf(" %d ", Comp);
    printf("%d ", Phy);
}
