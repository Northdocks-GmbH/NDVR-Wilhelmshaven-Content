#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UMG/Public/Components/WidgetInteractionComponent.h"
#include "Widgets/Input/SEditableText.h"
#include "Widgets/Text/SMultiLineEditableText.h"
#include "NDStaticFunctions.generated.h"


UCLASS()
class NDCOMMONASSETS_API UNDStaticFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	//System Information
	UFUNCTION(BlueprintPure, Category = "Northdocks|System")
	static FString GetProjectVersion();

	UFUNCTION(BlueprintCallable,Category="Northdocks|System")
	static bool IsModuleLoaded(FName ModuleName);

	//Files
	
	UFUNCTION(BlueprintCallable, Category = "Northdocks|File IO")
	static void GetFiles(FString Path, FString Extension, TArray<FString>& Files);

	UFUNCTION(BlueprintCallable, Category = "Northdocks|File IO")
	static void GetFolders(FString Path, TArray<FString>& Folders);

	UFUNCTION(BlueprintCallable, Category = "Northdocks|File IO")
	static bool DeleteFile(FString Path ,FString FileName);

	//File IO
	
	UFUNCTION(BlueprintCallable, Category = "Northdocks|File IO")
	static bool LoadFileToString(FString FileName, FString& Result);

	UFUNCTION(BlueprintCallable, Category = "Northdocks|File IO")
	static bool SaveStringToFile(FString FileName, FString Text, bool Append);

	//Sort

	UFUNCTION(BlueprintCallable,Category="Northdocks|Sort")
	static void SortByDistance(AActor* RefActor, TArray<AActor*> InArray, TArray<AActor*>& OutArray);

	UFUNCTION(BlueprintCallable,Category="Northdocks|Sort")
	static void SortFloatArray(TArray<float> InArray, TArray<float>& OutArray);

	UFUNCTION(BlueprintCallable,Category="Northdocks|Sort")
	static void SortIndexMap(UPARAM(ref) TMap<int,float>& InMap);

	//Math
	UFUNCTION(BlueprintPure, Category="Northdocks|Math")
	static float GetFloatArrayAverage(const TArray<float>& Floats);

	UFUNCTION(BlueprintPure, Category="Northdocks|Math")
	static float GetFloatArraySum(const TArray<float>& Floats);

	UFUNCTION(BlueprintPure, Category="Northdocks|Math")
	static float NegateFloat(float A);
	
	//Widget
	UFUNCTION(BlueprintCallable,Category="Northdocks|Widget")
	static void SendBackspace(UWidgetInteractionComponent* Comp);

	UFUNCTION(BlueprintCallable,Category="Northdocks|Widget")
	static void SendNewline(UWidgetInteractionComponent* Comp);

	/*
	UFUNCTION(BlueprintCallable,Category="Northdocks|Widget")
	static FString WidgetCompTest(UWidgetInteractionComponent* Comp)
	{
		
		auto LastWidget = Comp->GetHoveredWidgetPath().GetLastWidget();
		if(LastWidget.IsValid())
		{			
			auto LastWidgetPin = LastWidget.Pin();

			if(LastWidgetPin->GetType() == "SMultiLineEditableText")
			{
				SMultiLineEditableText* EditableText1 = static_cast<SMultiLineEditableText*>(LastWidgetPin.Get());
				if(EditableText1 != NULL)
				{
					FText Text1 = FText::FromString(EditableText1->GetText().ToString() + "\n");
					return "Alles Top!";
				}
				return "oh oh";
			}
			return "Invalid Type: "+LastWidgetPin->GetType().ToString();
		}
		return "No Valid Widget Found";

	//FSlateApplication::Get().GetKeyboardFocusedWidget();
	}
	*/
};
