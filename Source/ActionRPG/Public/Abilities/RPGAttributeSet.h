// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ActionRPG.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "RPGAttributeSet.generated.h"

// Uses macros from AttributeSet.h
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/** This holds all of the attributes used by abilities, it instantiates a copy of this on every character */
UCLASS()
class ACTIONRPG_API URPGAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:

	// Constructor and overrides
	URPGAttributeSet();
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	/** Current Health, when 0 we expect owner to die. Capped by MaxHealth */
	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing=OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Health)

	/** MaxHealth is its own attribute, since GameplayEffects may modify it */
	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing=OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, MaxHealth)

	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_HealthRegen)
	FGameplayAttributeData HealthRegen;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, HealthRegen)

	/** Current Mana, used to execute special abilities. Capped by MaxMana */
	UPROPERTY(BlueprintReadOnly, Category = "Mana", ReplicatedUsing=OnRep_Mana)
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Mana)

	/** MaxMana is its own attribute, since GameplayEffects may modify it */
	UPROPERTY(BlueprintReadOnly, Category = "Mana", ReplicatedUsing=OnRep_MaxMana)
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, MaxMana)

	/** MaxMana is its own attribute, since GameplayEffects may modify it */
	UPROPERTY(BlueprintReadOnly, Category = "Mana", ReplicatedUsing = OnRep_ManaRegen)
	FGameplayAttributeData ManaRegen;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ManaRegen)

	UPROPERTY(BlueprintReadOnly, Category = "Stamina", ReplicatedUsing = OnRep_Stamina)
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Stamina)

	UPROPERTY(BlueprintReadOnly, Category = "Stamina", ReplicatedUsing = OnRep_MaxStamina)
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, MaxStamina)

	UPROPERTY(BlueprintReadOnly, Category = "Stamina", ReplicatedUsing = OnRep_StaminaRegen)
	FGameplayAttributeData StaminaRegen;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, StaminaRegen)

	/** MoveSpeed affects how fast characters can move */
	UPROPERTY(BlueprintReadOnly, Category = "MoveSpeed", ReplicatedUsing = OnRep_MoveSpeed)
	FGameplayAttributeData MoveSpeed;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, MoveSpeed)

	/** Damage is a 'temporary' attribute used by the DamageExecution to calculate final damage, which then turns into -Health */
	UPROPERTY(BlueprintReadOnly, Category = "Damage", meta = (HideFromLevelInfos))
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Damage)


	//MY PROPERTIES
	/**********************************************************************************************************
	Defensive properties
	**********************************************************************************************************/
	UPROPERTY(BlueprintReadOnly, Category = "Global Damage", ReplicatedUsing = OnRep_GlobalDamageReductionPercent)
	FGameplayAttributeData GlobalDamageReductionPercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, GlobalDamageReductionPercent)

	UPROPERTY(BlueprintReadOnly, Category = "Physical Damage", ReplicatedUsing = OnRep_PhysicalResistancePercent)
	FGameplayAttributeData PhysicalResistancePercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, PhysicalResistancePercent)

	UPROPERTY(BlueprintReadOnly, Category = "Fire Damage", ReplicatedUsing = OnRep_FireResistancePercent)
	FGameplayAttributeData FireResistancePercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FireResistancePercent)

	UPROPERTY(BlueprintReadOnly, Category = "Cold Damage", ReplicatedUsing = OnRep_ColdResistancePercent)
	FGameplayAttributeData ColdResistancePercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ColdResistancePercent)

	UPROPERTY(BlueprintReadOnly, Category = "Lightning Damage", ReplicatedUsing = OnRep_LightningResistancePercent)
	FGameplayAttributeData LightningResistancePercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, LightningResistancePercent)

	UPROPERTY(BlueprintReadOnly, Category = "Chaos Damage", ReplicatedUsing = OnRep_ChaosResistancePercent)
	FGameplayAttributeData ChaosResistancePercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ChaosResistancePercent)

	UPROPERTY(BlueprintReadOnly, Category = "Dodge", ReplicatedUsing = OnRep_DodgeEffectiveness)
	FGameplayAttributeData DodgeEffectiveness;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, DodgeEffectiveness)

	UPROPERTY(BlueprintReadOnly, Category = "Dodge", ReplicatedUsing = OnRep_DodgeDamageReductionPercent)
	FGameplayAttributeData DodgeDamageReductionPercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, DodgeDamageReductionPercent)

	UPROPERTY(BlueprintReadOnly, Category = "Block", ReplicatedUsing = OnRep_BlockEffectiveness)
	FGameplayAttributeData BlockEffectiveness;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, BlockEffectiveness)

	UPROPERTY(BlueprintReadOnly, Category = "Block", ReplicatedUsing = OnRep_BlockDamageReductionPercent)
	FGameplayAttributeData BlockDamageReductionPercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, BlockDamageReductionPercent)

	
		

	/**********************************************************************************************************
	Offensive properties
	**********************************************************************************************************/

	UPROPERTY(BlueprintReadOnly, Category = "Global Damage", ReplicatedUsing = OnRep_GlobalDamagePercent)
	FGameplayAttributeData GlobalDamagePercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, GlobalDamagePercent)

	UPROPERTY(BlueprintReadOnly, Category = "Physical Damage", ReplicatedUsing = OnRep_PhysicalDamagePercent)
	FGameplayAttributeData PhysicalDamagePercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, PhysicalDamagePercent)

	UPROPERTY(BlueprintReadOnly, Category = "Fire Damage", ReplicatedUsing = OnRep_FireDamagePercent)
	FGameplayAttributeData FireDamagePercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FireDamagePercent)

	UPROPERTY(BlueprintReadOnly, Category = "Cold Damage", ReplicatedUsing = OnRep_ColdDamagePercent)
	FGameplayAttributeData ColdDamagePercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ColdDamagePercent)

	UPROPERTY(BlueprintReadOnly, Category = "Lightning Damage", ReplicatedUsing = OnRep_LightningDamagePercent)
	FGameplayAttributeData LightningDamagePercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, LightningDamagePercent)

	UPROPERTY(BlueprintReadOnly, Category = "Chaos Damage", ReplicatedUsing = OnRep_ChaosDamagePercent)
	FGameplayAttributeData ChaosDamagePercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ChaosDamagePercent)

	UPROPERTY(BlueprintReadOnly, Category = "Critical Hit Damage", ReplicatedUsing = OnRep_CriticalHitDamagePercent)
	FGameplayAttributeData CriticalHitDamagePercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, CriticalHitDamagePercent)

	/**********************************************************************************************************
	Conditional Damage
	**********************************************************************************************************/

	UPROPERTY(BlueprintReadOnly, Category = "Magic Damage", ReplicatedUsing = OnRep_MagicDamagePercent)
	FGameplayAttributeData MagicDamagePercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, MagicDamagePercent)

	UPROPERTY(BlueprintReadOnly, Category = "Melee Damage", ReplicatedUsing = OnRep_MeleeDamagePercent)
	FGameplayAttributeData MeleeDamagePercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, MeleeDamagePercent)

	UPROPERTY(BlueprintReadOnly, Category = "Attack Damage", ReplicatedUsing = OnRep_AttackDamagePercent)
	FGameplayAttributeData AttackDamagePercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, AttackDamagePercent)

	UPROPERTY(BlueprintReadOnly, Category = "Spell Damage", ReplicatedUsing = OnRep_SpellDamagePercent)
	FGameplayAttributeData SpellDamagePercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, SpellDamagePercent)

	UPROPERTY(BlueprintReadOnly, Category = "Projectile Damage", ReplicatedUsing = OnRep_ProjectileDamagePercent)
	FGameplayAttributeData ProjectileDamagePercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ProjectileDamagePercent)

	UPROPERTY(BlueprintReadOnly, Category = "Ranged Damage", ReplicatedUsing = OnRep_RangedDamagePercent)
	FGameplayAttributeData RangedDamagePercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, RangedDamagePercent)

	UPROPERTY(BlueprintReadOnly, Category = "Minion Damage", ReplicatedUsing = OnRep_MinionDamagePercent)
	FGameplayAttributeData MinionDamagePercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, MinionDamagePercent)

	UPROPERTY(BlueprintReadOnly, Category = "Damage Over Time", ReplicatedUsing = OnRep_DamageOverTimeDamage)
	FGameplayAttributeData DamageOverTimeDamage;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, DamageOverTimeDamage)

	UPROPERTY(BlueprintReadOnly, Category = "Area Damage", ReplicatedUsing = OnRep_AreaDamagePercent)
	FGameplayAttributeData AreaDamagePercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, AreaDamagePercent)

	/**********************************************************************************************************
	Elemental Conversion
	**********************************************************************************************************/

	/**********************************************************************************************************
	Physical Conversion
	**********************************************************************************************************/

	UPROPERTY(BlueprintReadOnly, Category = "Damage Conversion", ReplicatedUsing = OnRep_PhysicalToFireConversionPercent)
	FGameplayAttributeData PhysicalToFireConversionPercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, PhysicalToFireConversionPercent)

	UPROPERTY(BlueprintReadOnly, Category = "Damage Conversion", ReplicatedUsing = OnRep_PhysicalToColdConversionPercent)
	FGameplayAttributeData PhysicalToColdConversionPercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, PhysicalToColdConversionPercent)

	UPROPERTY(BlueprintReadOnly, Category = "Damage Conversion", ReplicatedUsing = OnRep_PhysicalToLightningConversionPercent)
	FGameplayAttributeData PhysicalToLightningConversionPercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, PhysicalToLightningConversionPercent)

	UPROPERTY(BlueprintReadOnly, Category = "Damage Conversion", ReplicatedUsing = OnRep_PhysicalToChaosConversionPercent)
	FGameplayAttributeData PhysicalToChaosConversionPercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, PhysicalToChaosConversionPercent)

	/**********************************************************************************************************
	Fire Conversion
	**********************************************************************************************************/

	UPROPERTY(BlueprintReadOnly, Category = "Damage Conversion", ReplicatedUsing = OnRep_FireToPhysicalConversionPercent)
	FGameplayAttributeData FireToPhysicalConversionPercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FireToPhysicalConversionPercent)

	UPROPERTY(BlueprintReadOnly, Category = "Damage Conversion", ReplicatedUsing = OnRep_FireToColdConversionPercent)
	FGameplayAttributeData FireToColdConversionPercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FireToColdConversionPercent)

	UPROPERTY(BlueprintReadOnly, Category = "Damage Conversion", ReplicatedUsing = OnRep_FireToLightningConversionPercent)
	FGameplayAttributeData FireToLightningConversionPercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FireToLightningConversionPercent)

	UPROPERTY(BlueprintReadOnly, Category = "Damage Conversion", ReplicatedUsing = OnRep_FireToChaosConversionPercent)
	FGameplayAttributeData FireToChaosConversionPercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FireToChaosConversionPercent)

	/**********************************************************************************************************
	Cold Conversion
	**********************************************************************************************************/

	UPROPERTY(BlueprintReadOnly, Category = "Damage Conversion", ReplicatedUsing = OnRep_ColdToPhysicalConversionPercent)
	FGameplayAttributeData ColdToPhysicalConversionPercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ColdToPhysicalConversionPercent)

	UPROPERTY(BlueprintReadOnly, Category = "Damage Conversion", ReplicatedUsing = OnRep_ColdToFireConversionPercent)
	FGameplayAttributeData ColdToFireConversionPercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ColdToFireConversionPercent)

	UPROPERTY(BlueprintReadOnly, Category = "Damage Conversion", ReplicatedUsing = OnRep_ColdToLightningConversionPercent)
	FGameplayAttributeData ColdToLightningConversionPercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ColdToLightningConversionPercent)

	UPROPERTY(BlueprintReadOnly, Category = "Damage Conversion", ReplicatedUsing = OnRep_ColdToChaosConversionPercent)
	FGameplayAttributeData ColdToChaosConversionPercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ColdToChaosConversionPercent)

	/**********************************************************************************************************
	Lightning Conversion
	**********************************************************************************************************/

	UPROPERTY(BlueprintReadOnly, Category = "Damage Conversion", ReplicatedUsing = OnRep_LightningToPhysicalConversionPercent)
	FGameplayAttributeData LightningToPhysicalConversionPercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, LightningToPhysicalConversionPercent)

	UPROPERTY(BlueprintReadOnly, Category = "Damage Conversion", ReplicatedUsing = OnRep_LightningToFireConversionPercent)
	FGameplayAttributeData LightningToFireConversionPercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, LightningToFireConversionPercent)

	UPROPERTY(BlueprintReadOnly, Category = "Damage Conversion", ReplicatedUsing = OnRep_LightningToColdConversionPercent)
	FGameplayAttributeData LightningToColdConversionPercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, LightningToColdConversionPercent)

	UPROPERTY(BlueprintReadOnly, Category = "Damage Conversion", ReplicatedUsing = OnRep_LightningToChaosConversionPercent)
	FGameplayAttributeData LightningToChaosConversionPercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, LightningToChaosConversionPercent)

	/**********************************************************************************************************
	Chaos Conversion
	**********************************************************************************************************/

	UPROPERTY(BlueprintReadOnly, Category = "Damage Conversion", ReplicatedUsing = OnRep_ChaosToPhysicalConversionPercent)
	FGameplayAttributeData ChaosToPhysicalConversionPercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ChaosToPhysicalConversionPercent)

	UPROPERTY(BlueprintReadOnly, Category = "Damage Conversion", ReplicatedUsing = OnRep_ChaosToFireConversionPercent)
	FGameplayAttributeData ChaosToFireConversionPercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ChaosToFireConversionPercent)

	UPROPERTY(BlueprintReadOnly, Category = "Damage Conversion", ReplicatedUsing = OnRep_ChaosToColdConversionPercent)
	FGameplayAttributeData ChaosToColdConversionPercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ChaosToColdConversionPercent)

	UPROPERTY(BlueprintReadOnly, Category = "Damage Conversion", ReplicatedUsing = OnRep_ChaosToLightningConversionPercent)
	FGameplayAttributeData ChaosToLightningConversionPercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ChaosToLightningConversionPercent)

	/**********************************************************************************************************
	Weapon damage properties
	**********************************************************************************************************/

	/*
	UPROPERTY(BlueprintReadOnly, Category = "Weapon Damage", ReplicatedUsing = OnRep_WeaponDamageSwordPercent)
	FGameplayAttributeData WeaponDamageSwordPercent;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, WeaponDamageSwordPercent)
	*/

	/**********************************************************************************************************
	Misc properties, like duration/area of effect
	**********************************************************************************************************/

	UPROPERTY(BlueprintReadOnly, Category = "Duration", ReplicatedUsing = OnRep_Duration)
	FGameplayAttributeData Duration;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, Duration)

	UPROPERTY(BlueprintReadOnly, Category = "Area of Effect", ReplicatedUsing = OnRep_AreaOfEffect)
	FGameplayAttributeData AreaOfEffect;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, AreaOfEffect)

	/**********************************************************************************************************
	Result properties, don't modify these directly
	**********************************************************************************************************/

	UPROPERTY(BlueprintReadOnly, Category = "Physical Damage", ReplicatedUsing = OnRep_PhysicalDamage)
	FGameplayAttributeData PhysicalDamage;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, PhysicalDamage)

	UPROPERTY(BlueprintReadOnly, Category = "Fire Damage", ReplicatedUsing = OnRep_FireDamage)
	FGameplayAttributeData FireDamage;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, FireDamage)

	UPROPERTY(BlueprintReadOnly, Category = "Cold Damage", ReplicatedUsing = OnRep_ColdDamage)
	FGameplayAttributeData ColdDamage;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ColdDamage)

	UPROPERTY(BlueprintReadOnly, Category = "Lightning Damage", ReplicatedUsing = OnRep_LightningDamage)
	FGameplayAttributeData LightningDamage;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, LightningDamage)

	UPROPERTY(BlueprintReadOnly, Category = "Chaos Damage", ReplicatedUsing = OnRep_ChaosDamage)
	FGameplayAttributeData ChaosDamage;
	ATTRIBUTE_ACCESSORS(URPGAttributeSet, ChaosDamage)

protected:
	/** Helper function to proportionally adjust the value of an attribute when it's associated max attribute changes. (i.e. When MaxHealth increases, Health increases by an amount that maintains the same percentage as before) */
	void AdjustAttributeForMaxChange(FGameplayAttributeData& AffectedAttribute, const FGameplayAttributeData& MaxAttribute, float NewMaxValue, const FGameplayAttribute& AffectedAttributeProperty);

	// These OnRep functions exist to make sure that the ability system internal representations are synchronized properly during replication
	UFUNCTION()
	virtual void OnRep_Health();

	UFUNCTION()
	virtual void OnRep_MaxHealth();

	UFUNCTION()
	virtual void OnRep_HealthRegen();

	UFUNCTION()
	virtual void OnRep_Mana();

	UFUNCTION()
	virtual void OnRep_MaxMana();

	UFUNCTION()
	virtual void OnRep_ManaRegen();

	UFUNCTION()
	virtual void OnRep_Stamina();

	UFUNCTION()
	virtual void OnRep_MaxStamina();

	UFUNCTION()
	virtual void OnRep_StaminaRegen();

	UFUNCTION()
	virtual void OnRep_MoveSpeed();
	
	/**********************************************************************************************************
	Defensive properties
	**********************************************************************************************************/
	UFUNCTION()
	virtual void OnRep_GlobalDamageReductionPercent();
	
	UFUNCTION()
	virtual void OnRep_PhysicalResistancePercent();

	UFUNCTION()
	virtual void OnRep_FireResistancePercent();

	UFUNCTION()
	virtual void OnRep_ColdResistancePercent();

	UFUNCTION()
	virtual void OnRep_LightningResistancePercent();

	UFUNCTION()
	virtual void OnRep_ChaosResistancePercent();

	UFUNCTION()
	virtual void OnRep_DodgeEffectiveness();

	UFUNCTION()
	virtual void OnRep_DodgeDamageReductionPercent();

	UFUNCTION()
	virtual void OnRep_BlockEffectiveness();

	UFUNCTION()
	virtual void OnRep_BlockDamageReductionPercent();
	
	/**********************************************************************************************************
	Offensive properties
	**********************************************************************************************************/
	UFUNCTION()
	virtual void OnRep_GlobalDamagePercent();

	UFUNCTION()
	virtual void OnRep_PhysicalDamagePercent();

	UFUNCTION()
	virtual void OnRep_FireDamagePercent();

	UFUNCTION()
	virtual void OnRep_ColdDamagePercent();

	UFUNCTION()
	virtual void OnRep_LightningDamagePercent();

	UFUNCTION()
	virtual void OnRep_ChaosDamagePercent();

	UFUNCTION()
	virtual void OnRep_CriticalHitDamagePercent();

	/**********************************************************************************************************
	Conditional Damage
	**********************************************************************************************************/

	UFUNCTION()
	virtual void OnRep_MagicDamagePercent();

	UFUNCTION()
	virtual void OnRep_MeleeDamagePercent();

	UFUNCTION()
	virtual void OnRep_AttackDamagePercent();

	UFUNCTION()
	virtual void OnRep_SpellDamagePercent();

	UFUNCTION()
	virtual void OnRep_ProjectileDamagePercent();

	UFUNCTION()
	virtual void OnRep_RangedDamagePercent();

	UFUNCTION()
	virtual void OnRep_MinionDamagePercent();

	UFUNCTION()
	virtual void OnRep_DamageOverTimeDamage();

	UFUNCTION()
	virtual void OnRep_AreaDamagePercent();


	/**********************************************************************************************************
	Elemental Conversion
	**********************************************************************************************************/

	/**********************************************************************************************************
	Physical Conversion
	**********************************************************************************************************/

	UFUNCTION()
	virtual void OnRep_PhysicalToFireConversionPercent();

	UFUNCTION()
	virtual void OnRep_PhysicalToColdConversionPercent();

	UFUNCTION()
	virtual void OnRep_PhysicalToLightningConversionPercent();

	UFUNCTION()
	virtual void OnRep_PhysicalToChaosConversionPercent();

	/**********************************************************************************************************
	Fire Conversion
	**********************************************************************************************************/

	UFUNCTION()
	virtual void OnRep_FireToPhysicalConversionPercent();

	UFUNCTION()
	virtual void OnRep_FireToColdConversionPercent();

	UFUNCTION()
	virtual void OnRep_FireToLightningConversionPercent();

	UFUNCTION()
	virtual void OnRep_FireToChaosConversionPercent();

	/**********************************************************************************************************
	Cold Conversion
	**********************************************************************************************************/

	UFUNCTION()
	virtual void OnRep_ColdToPhysicalConversionPercent();

	UFUNCTION()
	virtual void OnRep_ColdToFireConversionPercent();

	UFUNCTION()
	virtual void OnRep_ColdToLightningConversionPercent();

	UFUNCTION()
	virtual void OnRep_ColdToChaosConversionPercent();

	/**********************************************************************************************************
	Lightning Conversion
	**********************************************************************************************************/

	UFUNCTION()
	virtual void OnRep_LightningToPhysicalConversionPercent();

	UFUNCTION()
	virtual void OnRep_LightningToFireConversionPercent();

	UFUNCTION()
	virtual void OnRep_LightningToColdConversionPercent();

	UFUNCTION()
	virtual void OnRep_LightningToChaosConversionPercent();

	/**********************************************************************************************************
	Chaos Conversion
	**********************************************************************************************************/

	UFUNCTION()
	virtual void OnRep_ChaosToPhysicalConversionPercent();

	UFUNCTION()
	virtual void OnRep_ChaosToFireConversionPercent();

	UFUNCTION()
	virtual void OnRep_ChaosToColdConversionPercent();

	UFUNCTION()
	virtual void OnRep_ChaosToLightningConversionPercent();

	/**********************************************************************************************************
	Weapon damage properties
	**********************************************************************************************************/

	/*
	UFUNCTION()
	virtual void OnRep_WeaponDamageSwordPercent();
	*/

	/**********************************************************************************************************
	Misc properties, like duration/area of effect
	**********************************************************************************************************/
	UFUNCTION()
	virtual void OnRep_Duration();

	UFUNCTION()
	virtual void OnRep_AreaOfEffect();

	/**********************************************************************************************************
	Result properties, don't modify these directly
	**********************************************************************************************************/

	UFUNCTION()
	virtual void OnRep_PhysicalDamage();

	UFUNCTION()
	virtual void OnRep_FireDamage();

	UFUNCTION()
	virtual void OnRep_ColdDamage();

	UFUNCTION()
	virtual void OnRep_LightningDamage();

	UFUNCTION()
	virtual void OnRep_ChaosDamage();

};