#pragma once

namespace GameObject {
	enum ECallbackType {
		eTradeStart = u32(0),
		eTradeStop,
		eTradeSellBuyItem,
		eTradePerformTradeOperation,

		eZoneEnter,
		eZoneExit,
		eExitLevelBorder,
		eEnterLevelBorder,
		eDeath,

		ePatrolPathInPoint,

		eInventoryPda,
		eInventoryInfo,
		eArticleInfo,
		eTaskStateChange,
		eMapLocationAdded,

		eUseObject,

		eHit,

		eSound,

		eActionTypeMovement,
		eActionTypeWatch,
		eActionTypeRemoved,
		eActionTypeAnimation,
		eActionTypeSound,
		eActionTypeParticle,
		eActionTypeObject,

		eActorSleep,

		eHelicopterOnPoint,
		eHelicopterOnHit,

		eOnItemTake,
		eOnItemDrop,

		eScriptAnimation,
		
		eTraderGlobalAnimationRequest,
		eTraderHeadAnimationRequest,
		eTraderSoundEnd,

		eInvBoxItemTake,
		eWeaponNoAmmoAvailable,
		// ����������
		eOnKeyPress,//+
		eOnKeyRelease,//+
		eOnKeyHold,//+

		//����
		eOnMouseMove,//+
		eOnMouseWheel,//+

		// ���������
		eOnItemBelt,//+
		eOnItemSlot,//+
		eOnItemRuck,//+

		// ������
		eSwitchTorch,//+

		//����� �����
		eChangeSlot,

		// Called when the player zooms their weapon in or out.
		eOnActorWeaponZoomIn,//+
		eOnActorWeaponZoomOut,//+

		// vehicle
		eAttachVehicle,//+
		eDetachVehicle,//+

		//box events
		eOnInvBoxItemTake,
		eOnInvBoxItemDrop,

		// actor menu
		eActorMenuOpen,

		eOnThrowGrenade,
		eDummy = u32(-1),
	};
};

enum EBoneCallbackType{
	bctDummy			= u32(0),	// 0 - required!!!
	bctPhysics,
	bctCustom,
	bctForceU32			= u32(-1),
};
