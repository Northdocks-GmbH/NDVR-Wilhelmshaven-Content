// Fill out your copyright notice in the Description page of Project Settings.


#include "NDStaticFunctions.h"

void UNDStaticFunctions::GetFiles(FString Path, FString Extension, TArray<FString>& Files)
{
	FPaths::NormalizeDirectoryName(Path);
	IFileManager& FileManager = IFileManager::Get();

	//if (FullPath.Len() < 1) return false;

	if (Extension == "")
	{
		Extension = "*.*";
	}
	else
	{
		Extension = (Extension.Left(1) == ".") ? "*" + Extension : "*." + Extension;
	}

	FString FinalPath = Path + "/" + Extension;

	FileManager.FindFiles(Files, *FinalPath, true, false);
}

void UNDStaticFunctions::GetFolders(FString Path, TArray<FString>& Folders)
{
	FPaths::NormalizeDirectoryName(Path);
	IFileManager& FileManager = IFileManager::Get();

	Path = Path / "*";
	FileManager.FindFiles(Folders, *Path, false, true);
}

bool UNDStaticFunctions::LoadFileToString(FString FileName, FString& Result)
{
	return FFileHelper::LoadFileToString(Result, *FileName);
}

bool UNDStaticFunctions::SaveStringToFile(FString FileName, FString Text, bool Append)
{
	if(Append)
	{
		FString Tmp;
		FFileHelper::LoadFileToString(Tmp, *FileName);
		return FFileHelper::SaveStringToFile(Tmp+Text, *FileName);
	}
	return FFileHelper::SaveStringToFile(Text, *FileName);
}

bool UNDStaticFunctions::DeleteFile(FString Path, FString FileName)
{
	FString MyFile = Path + FileName;
	if(!MyFile.IsEmpty())
	{
		if (FPaths::ValidatePath(MyFile) && FPaths::FileExists(MyFile))
		{
			IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();
			return FileManager.DeleteFile(*MyFile);
		}
	}
	return false;
}

void UNDStaticFunctions::SortByDistance(AActor* RefActor, TArray<AActor*> InArray, TArray<AActor*>& OutArray)
{
	InArray.Sort([RefActor](const AActor& A, const AActor& B)
	{
		return A.GetDistanceTo(RefActor) < B.GetDistanceTo(RefActor);
	});
	OutArray = InArray;
}

void UNDStaticFunctions::SortFloatArray(TArray<float> InArray, TArray<float>& OutArray)
{
	InArray.Sort();
	OutArray = InArray;
}

void UNDStaticFunctions::SortIndexMap(TMap<int, float>& InMap)
{
	InMap.ValueSort([](const float A, const float B)
	{
		return A < B;
	});
}

FString UNDStaticFunctions::GetProjectVersion()
{
	FString ProjectVersion;
	GConfig->GetString(TEXT("/Script/EngineSettings.GeneralProjectSettings"),
		TEXT("ProjectVersion"),
		ProjectVersion,
		GGameIni
		);
	return ProjectVersion;
}

bool UNDStaticFunctions::IsModuleLoaded(const FName ModuleName)
{
	return FModuleManager::Get().IsModuleLoaded(ModuleName);
}

float UNDStaticFunctions::GetFloatArrayAverage(const TArray<float>& Floats)
{
	float Sum(0.f);
	float Average(0.f);

	if (Floats.Num() > 0)
	{
		for (int32 VecIdx=0; VecIdx<Floats.Num(); VecIdx++)
		{
			Sum += Floats[VecIdx];
		}

		Average = Sum / Floats.Num();
	}

	return Average;
}

float UNDStaticFunctions::GetFloatArraySum(const TArray<float>& Floats)
{
	float Sum(0.f);

	if (Floats.Num() > 0)
	{
		for (int32 VecIdx=0; VecIdx<Floats.Num(); VecIdx++)
		{
			Sum += Floats[VecIdx];
		}
	}

	return Sum;
}

float UNDStaticFunctions::NegateFloat(float A)
{
	return -A;
}

void UNDStaticFunctions::SendBackspace(UWidgetInteractionComponent* Comp){
	Comp->SendKeyChar("\b");
}

void UNDStaticFunctions::SendNewline(UWidgetInteractionComponent* Comp){
	Comp->SendKeyChar("\n");
}


