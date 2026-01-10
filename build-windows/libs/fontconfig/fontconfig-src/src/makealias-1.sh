#!/bin/sh
SHELL=sh
SRCDIR=../src
HEAD=fcalias.h
TAIL=fcaliastail.h
rm -f $HEAD $TAIL
echo "#if HAVE_GNUC_ATTRIBUTE" >> $TAIL
for name in \
FcBlanksCreate \
FcBlanksDestroy \
FcBlanksAdd \
FcBlanksIsMember \
FcCacheDir \
FcCacheCopySet \
FcCacheSubdir \
FcCacheNumSubdir \
FcCacheNumFont \
FcDirCacheUnlink \
FcDirCacheValid \
FcDirCacheClean \
FcCacheCreateTagFile \
FcDirCacheCreateUUID \
FcDirCacheDeleteUUID \
FcConfigHome \
FcConfigEnableHome \
FcConfigGetFilename \
FcConfigFilename \
FcConfigCreate \
FcConfigReference \
FcConfigDestroy \
FcConfigSetCurrent \
FcConfigGetCurrent \
FcConfigUptoDate \
FcConfigBuildFonts \
FcConfigGetFontDirs \
FcConfigGetConfigDirs \
FcConfigGetConfigFiles \
FcConfigGetCache \
FcConfigGetBlanks \
FcConfigGetCacheDirs \
FcConfigGetRescanInterval \
FcConfigSetRescanInterval \
FcConfigGetFonts \
FcConfigAppFontAddFile \
FcConfigAppFontAddDir \
FcConfigAppFontClear \
FcConfigSubstituteWithPat \
FcConfigSubstitute \
FcConfigGetSysRoot \
FcConfigSetSysRoot \
FcConfigFileInfoIterInit \
FcConfigFileInfoIterNext \
FcConfigFileInfoIterGet \
FcCharSetCreate \
FcCharSetNew \
FcCharSetDestroy \
FcCharSetAddChar \
FcCharSetDelChar \
FcCharSetCopy \
FcCharSetEqual \
FcCharSetIntersect \
FcCharSetUnion \
FcCharSetSubtract \
FcCharSetMerge \
FcCharSetHasChar \
FcCharSetCount \
FcCharSetIntersectCount \
FcCharSetSubtractCount \
FcCharSetIsSubset \
FcCharSetFirstPage \
FcCharSetNextPage \
FcCharSetCoverage \
FcValuePrint \
FcPatternPrint \
FcFontSetPrint \
FcGetDefaultLangs \
FcDefaultSubstitute \
FcFileIsDir \
FcFileScan \
FcDirScan \
FcDirSave \
FcDirCacheLoad \
FcDirCacheRescan \
FcDirCacheRead \
FcDirCacheLoadFile \
FcDirCacheUnload \
FcFreeTypeQuery \
FcFreeTypeQueryAll \
FcFontSetCreate \
FcFontSetDestroy \
FcFontSetAdd \
FcInitLoadConfig \
FcInitLoadConfigAndFonts \
FcInit \
FcFini \
FcGetVersion \
FcInitReinitialize \
FcInitBringUptoDate \
FcGetLangs \
FcLangNormalize \
FcLangGetCharSet \
FcLangSetCreate \
FcLangSetDestroy \
FcLangSetCopy \
FcLangSetAdd \
FcLangSetDel \
FcLangSetHasLang \
FcLangSetCompare \
FcLangSetContains \
FcLangSetEqual \
FcLangSetHash \
FcLangSetGetLangs \
FcLangSetUnion \
FcLangSetSubtract \
FcObjectSetCreate \
FcObjectSetAdd \
FcObjectSetDestroy \
FcObjectSetVaBuild \
FcObjectSetBuild \
FcFontSetList \
FcFontList \
FcAtomicCreate \
FcAtomicLock \
FcAtomicNewFile \
FcAtomicOrigFile \
FcAtomicReplaceOrig \
FcAtomicDeleteNew \
FcAtomicUnlock \
FcAtomicDestroy \
FcFontSetMatch \
FcFontMatch \
FcFontRenderPrepare \
FcFontSetSort \
FcFontSort \
FcFontSetSortDestroy \
FcMatrixCopy \
FcMatrixEqual \
FcMatrixMultiply \
FcMatrixRotate \
FcMatrixScale \
FcMatrixShear \
FcNameRegisterObjectTypes \
FcNameUnregisterObjectTypes \
FcNameGetObjectType \
FcNameRegisterConstants \
FcNameUnregisterConstants \
FcNameGetConstant \
FcNameGetConstantFor \
FcNameConstant \
FcNameParse \
FcNameUnparse \
FcPatternCreate \
FcPatternDuplicate \
FcPatternReference \
FcPatternFilter \
FcValueDestroy \
FcValueEqual \
FcValueSave \
FcPatternDestroy \
FcPatternObjectCount \
FcPatternEqual \
FcPatternEqualSubset \
FcPatternHash \
FcPatternAdd \
FcPatternAddWeak \
FcPatternGet \
FcPatternGetWithBinding \
FcPatternDel \
FcPatternRemove \
FcPatternAddInteger \
FcPatternAddDouble \
FcPatternAddString \
FcPatternAddMatrix \
FcPatternAddCharSet \
FcPatternAddBool \
FcPatternAddLangSet \
FcPatternAddRange \
FcPatternGetInteger \
FcPatternGetDouble \
FcPatternGetString \
FcPatternGetMatrix \
FcPatternGetCharSet \
FcPatternGetBool \
FcPatternGetLangSet \
FcPatternGetRange \
FcPatternVaBuild \
FcPatternBuild \
FcPatternFormat \
FcRangeCreateDouble \
FcRangeCreateInteger \
FcRangeDestroy \
FcRangeCopy \
FcRangeGetDouble \
FcPatternIterStart \
FcPatternIterNext \
FcPatternIterEqual \
FcPatternFindIter \
FcPatternIterIsValid \
FcPatternIterGetObject \
FcPatternIterValueCount \
FcPatternIterGetValue \
FcWeightFromOpenType \
FcWeightFromOpenTypeDouble \
FcWeightToOpenType \
FcWeightToOpenTypeDouble \
FcStrCopy \
FcStrCopyFilename \
FcStrPlus \
FcStrFree \
FcStrDowncase \
FcStrCmpIgnoreCase \
FcStrCmp \
FcStrStrIgnoreCase \
FcStrStr \
FcUtf8ToUcs4 \
FcUtf8Len \
FcUcs4ToUtf8 \
FcUtf16ToUcs4 \
FcUtf16Len \
FcStrBuildFilename \
FcStrDirname \
FcStrBasename \
FcStrSetCreate \
FcStrSetMember \
FcStrSetEqual \
FcStrSetAdd \
FcStrSetAddFilename \
FcStrSetDel \
FcStrSetDestroy \
FcStrListCreate \
FcStrListFirst \
FcStrListNext \
FcStrListDone \
FcConfigParseAndLoad \
FcConfigParseAndLoadFromMemory \
FcConfigGetRescanInverval \
FcConfigSetRescanInverval
do
	case $name in
	FcCacheDir|FcCacheSubdir)
		;;
	*)
		alias="IA__$name"
		hattr='__attribute((visibility("hidden")))'
		echo "extern __typeof ($name) $alias $hattr;" >> $HEAD
		echo "#define $name $alias" >> $HEAD
		grep -l '^'$name'[ (]' "$SRCDIR"/*.c | head -1 | sed -e 's/^.*\/\([^.]*\)\.c/#ifdef __\1__/' >> $TAIL
		echo "#undef $name" >> $TAIL
		cattr='__attribute((alias("'$alias'"), visibility("default")))'
		echo "extern __typeof ($name) $name $cattr;" >> $TAIL
		echo "#endif" >> $TAIL
		;;
	esac
done
echo "#endif" >> $TAIL
