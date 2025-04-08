#include "FluTreeViewDemo.h"

FluTreeViewDemo::FluTreeViewDemo(FluWidget* parent /*= nullptr*/) : FluTemplateDemo(parent)
{
    m_treeView = new FluTreeView(this);
    m_treeView->setHeaderHidden(true);
    m_treeView->setColumnCount(1);

    auto workDocumentsItem = new QTreeWidgetItem({"Work Documents"});
    workDocumentsItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsAutoTristate);
    workDocumentsItem->setCheckState(0, Qt::Unchecked);

    auto xyzFunctionnalSpecItem = new QTreeWidgetItem({"XYZ Functional Spec"});
    xyzFunctionnalSpecItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsAutoTristate);
    xyzFunctionnalSpecItem->setCheckState(0, Qt::Unchecked);

    auto featureScheduleItem = new QTreeWidgetItem({"Feature Schedule"});
    featureScheduleItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsAutoTristate);
    featureScheduleItem->setCheckState(0, Qt::Unchecked);

    auto overallProjectPlanItem = new QTreeWidgetItem({"Overal Project Plan"});
    overallProjectPlanItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsAutoTristate);
    overallProjectPlanItem->setCheckState(0, Qt::Unchecked);

    auto featureResourcesAllocationItem = new QTreeWidgetItem({"Feature Resources Allocation"});
    featureResourcesAllocationItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsAutoTristate);
    featureResourcesAllocationItem->setCheckState(0, Qt::Unchecked);

    auto personalDocumentsItem = new QTreeWidgetItem({"Personal Documents"});
    personalDocumentsItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsAutoTristate);
    personalDocumentsItem->setCheckState(0, Qt::Unchecked);

    auto homeRemodelItem = new QTreeWidgetItem({"Contractor Contact Info"});
    homeRemodelItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsAutoTristate);
    homeRemodelItem->setCheckState(0, Qt::Unchecked);

    auto paintColorSchemeItem = new QTreeWidgetItem({"Paint Color Scheme"});
    paintColorSchemeItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsAutoTristate);
    paintColorSchemeItem->setCheckState(0, Qt::Unchecked);

    auto flooringWoodgrainTypeItem = new QTreeWidgetItem({"Flooring woodgrain type"});
    flooringWoodgrainTypeItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsAutoTristate);
    flooringWoodgrainTypeItem->setCheckState(0, Qt::Unchecked);

    auto kitchenCabinetStyleItem = new QTreeWidgetItem({"Kitchen cabinet style"});
    kitchenCabinetStyleItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsAutoTristate);
    kitchenCabinetStyleItem->setCheckState(0, Qt::Unchecked);

    workDocumentsItem->addChild(xyzFunctionnalSpecItem);
    workDocumentsItem->addChild(featureScheduleItem);
    workDocumentsItem->addChild(overallProjectPlanItem);
    workDocumentsItem->addChild(featureResourcesAllocationItem);

    personalDocumentsItem->addChild(homeRemodelItem);
    homeRemodelItem->addChild(paintColorSchemeItem);
    homeRemodelItem->addChild(flooringWoodgrainTypeItem);
    homeRemodelItem->addChild(kitchenCabinetStyleItem);

    m_treeView->addTopLevelItem(workDocumentsItem);
    m_treeView->addTopLevelItem(personalDocumentsItem);

    m_treeView->resize(400, 300);
    m_treeView->move(50, 100);
    resize(500, 800);
}
