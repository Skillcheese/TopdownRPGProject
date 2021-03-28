// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ActionRPG.h"
#include "Items/RPGItem.h"
#include "GameFramework/SaveGame.h"
#include "RPGSaveGame.generated.h"

/** List of versions, native code will handle fixups for any old versions */
namespace ERPGSaveGameVersion
{
	enum type
	{
		// Initial version
		Initial,
		// Added Inventory
		AddedInventory,
		// Added ItemData to store count/level
		AddedItemData,

		// -----<new versions must be added before this line>-------------------------------------------------
		VersionPlusOne,
		LatestVersion = VersionPlusOne - 1
	};
}

USTRUCT(BlueprintType)
struct ACTIONRPG_API FSaveStruct
{
	GENERATED_BODY()
public:
	FSaveStruct()
	{
		Data = FRPGItemData();
	}

	FSaveStruct(int32 _X_, int32 _Y_, FPrimaryAssetId Id, FRPGItemData data)
	{
		X = _X_;
		Y = _Y_;
		AssetId = Id;
		Data = data;
	}
	bool operator==(const FSaveStruct &other) const
	{ 
		return AssetId == other.AssetId && Data == other.Data; 
	}
	
	bool CheckIsValid() const
	{
		return Data.IsValid();
	}
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	FPrimaryAssetId AssetId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	FRPGItemData Data;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	int32 X;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	int32 Y;
};

/** Object that is written to and read from the save game archive, with a data version */
UCLASS(BlueprintType)
class ACTIONRPG_API URPGSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	/** Constructor */
	URPGSaveGame()
	{
		// Set to current version, this will get overwritten during serialization when loading
		SavedDataVersion = ERPGSaveGameVersion::LatestVersion;
	}

	/** Map of items to item data */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	TArray<FSaveStruct> InventoryData;

	/** Map of slotted items */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	TMap<FRPGItemSlot, FSaveStruct> SlottedItems;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	TArray<FPrimaryAssetId> SkillData;

	/** User's unique id */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = SaveGame)
	FString UserId;

protected:

	/** What LatestVersion was when the archive was saved */
	UPROPERTY()
	int32 SavedDataVersion;

	/** Overridden to allow version fixups */
	virtual void Serialize(FArchive& Ar) override;
};
