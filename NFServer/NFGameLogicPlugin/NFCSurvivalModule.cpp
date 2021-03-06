// -------------------------------------------------------------------------
//    @FileName			:    NFCSurvivalModule.cpp
//    @Author           :    LvSheng.Huang
//    @Date             :    2017-03-29
//    @Module           :    NFCSurvivalModule
//
// -------------------------------------------------------------------------

#include "NFCSurvivalModule.h"

bool NFCSurvivalModule::Init()
{

	mnMinPeopleForSurvivalMode = 50;

	return true;
}

bool NFCSurvivalModule::Shut()
{
	return true;
}

bool NFCSurvivalModule::Execute()
{
	return true;
}

bool NFCSurvivalModule::AfterInit()
{
	m_pElementModule = pPluginManager->FindModule<NFIElementModule>();
	m_pClassModule = pPluginManager->FindModule<NFIClassModule>();
	m_pPlayerRedisModule = pPluginManager->FindModule<NFIPlayerRedisModule>();
	m_pScheduleModule = pPluginManager->FindModule<NFIScheduleModule>();
	m_pNetModule = pPluginManager->FindModule<NFINetModule>();
	m_pKernelModule = pPluginManager->FindModule<NFIKernelModule>();
	m_pNoSqlModule = pPluginManager->FindModule<NFINoSqlModule>();
	m_pSceneAOIModule = pPluginManager->FindModule<NFISceneAOIModule>();
	m_pSceneProcessModule = pPluginManager->FindModule<NFISceneProcessModule>();
	m_pGameServerNet_ServerModule = pPluginManager->FindModule<NFIGameServerNet_ServerModule>();
	m_pLogModule = pPluginManager->FindModule<NFILogModule>();
	m_pRankModule = pPluginManager->FindModule<NFIRankModule>();


	m_pScheduleModule->AddSchedule("CheckSurvivalList", this, &NFCSurvivalModule::CheckSurvivalList, 10, -1);
	
	return true;
}

int NFCSurvivalModule::CheckSurvivalList(const std::string & strScheduleName, const float fIntervalTime, const int nCount)
{
	m_pLogModule->LogDebug(strScheduleName);

	if (m_pRankModule->GetRankListCount(NFIRankModule::RANK_TYPE::RT_SURVIVAL_MODE) >= mnMinPeopleForSurvivalMode)
	{

	}

	return 0;
}
