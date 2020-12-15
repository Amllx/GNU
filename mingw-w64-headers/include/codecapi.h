/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_CODECAPI
#define _INC_CODECAPI

#include <winapifamily.h>

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)

#ifdef UUID_GEN
#  define DEFINE_CODECAPI_GUID(name, guidstr, g1,g2,g3,g4,g5,g6,g7,g8,g9,g10,g11) \
    OUR_GUID_ENTRY(CODECAPI_##name, g1,g2,g3,g4,g5,g6,g7,g8,g9,g10,g11)
#else
#  ifndef DEFINE_GUIDSTRUCT
#    ifdef __cplusplus
#      define DEFINE_GUIDSTRUCT(g, n) struct n
#      define DEFINE_GUIDNAMED(n) __uuidof(struct n)
#    else
#      define DEFINE_GUIDSTRUCT(g, n) DEFINE_GUIDEX(n)
#      define DEFINE_GUIDNAMED(n) n
#    endif
#  endif
#  ifdef __CRT_UUID_DECL
#    define DEFINE_CODECAPI_GUID(name, guidstr, g1,g2,g3,g4,g5,g6,g7,g8,g9,g10,g11) \
       struct CODECAPI_##name; \
       __CRT_UUID_DECL(CODECAPI_##name, g1,g2,g3,g4,g5,g6,g7,g8,g9,g10,g11)
#    define DEFINE_CODECAPI_GUIDNAMED(name) __uuidof(CODECAPI_##name)
#  else
#    define DEFINE_CODECAPI_GUID(name, guidstr, g1,g2,g3,g4,g5,g6,g7,g8,g9,g10,g11) DEFINE_GUIDSTRUCT(guidstr, CODECAPI_##name);
#    define DEFINE_CODECAPI_GUIDNAMED(name) DEFINE_GUIDNAMED(CODECAPI_##name)
#  endif
#endif

  enum eAVEncCommonRateControlMode {
    eAVEncCommonRateControlMode_CBR = 0,
    eAVEncCommonRateControlMode_PeakConstrainedVBR = 1,
    eAVEncCommonRateControlMode_UnconstrainedVBR = 2,
    eAVEncCommonRateControlMode_Quality = 3,
    eAVEncCommonRateControlMode_LowDelayVBR = 4,
    eAVEncCommonRateControlMode_GlobalVBR = 5,
    eAVEncCommonRateControlMode_GlobalLowDelayVBR = 6
  };

  enum eAVEncCommonStreamEndHandling {
    eAVEncCommonStreamEndHandling_DiscardPartial = 0,
    eAVEncCommonStreamEndHandling_EnsureComplete = 1
  };

  enum eAVEncVideoOutputFrameRateConversion {
    eAVEncVideoOutputFrameRateConversion_Disable = 0,
    eAVEncVideoOutputFrameRateConversion_Enable = 1,
    eAVEncVideoOutputFrameRateConversion_Alias = 2
  };

  enum eAVDecVideoSoftwareDeinterlaceMode {
    eAVDecVideoSoftwareDeinterlaceMode_NoDeinterlacing = 0,
    eAVDecVideoSoftwareDeinterlaceMode_ProgressiveDeinterlacing = 1,
    eAVDecVideoSoftwareDeinterlaceMode_BOBDeinterlacing = 2,
    eAVDecVideoSoftwareDeinterlaceMode_SmartBOBDeinterlacing = 3
  };

  enum eAVFastDecodeMode {
    eVideoDecodeCompliant = 0,
    eVideoDecodeOptimalLF = 1,
    eVideoDecodeDisableLF = 2,
    eVideoDecodeFastest = 32
  };

  enum eAVDecVideoH264ErrorConcealment {
    eErrorConcealmentTypeDrop = 0,
    eErrorConcealmentTypeBasic = 1,
    eErrorConcealmentTypeAdvanced = 2,
    eErrorConcealmentTypeDXVASetBlack = 3
  };

  enum eAVDecVideoMPEG2ErrorConcealment {
    eErrorConcealmentOff = 0,
    eErrorConcealmentOn = 1
  };

  enum eAVDecVideoCodecType {
    eAVDecVideoCodecType_NOTPLAYING = 0,
    eAVDecVideoCodecType_MPEG2 = 1,
    eAVDecVideoCodecType_H264 = 2
  };

  enum eAVDecVideoDXVAMode {
    eAVDecVideoDXVAMode_NOTPLAYING = 0,
    eAVDecVideoDXVAMode_SW = 1,
    eAVDecVideoDXVAMode_MC = 2,
    eAVDecVideoDXVAMode_IDCT = 3,
    eAVDecVideoDXVAMode_VLD = 4
  };

  enum eAVDecVideoDXVABusEncryption {
    eAVDecVideoDXVABusEncryption_NONE = 0,
    eAVDecVideoDXVABusEncryption_PRIVATE = 1,
    eAVDecVideoDXVABusEncryption_AES = 2
  };

  enum eAVEncVideoSourceScanType {
    eAVEncVideoSourceScan_Automatic = 0,
    eAVEncVideoSourceScan_Interlaced = 1,
    eAVEncVideoSourceScan_Progressive = 2
  };

  enum eAVEncVideoOutputScanType {
    eAVEncVideoOutputScan_Progressive = 0,
    eAVEncVideoOutputScan_Interlaced = 1,
    eAVEncVideoOutputScan_SameAsInput = 2,
    eAVEncVideoOutputScan_Automatic = 3
  };

  enum eAVEncVideoFilmContent {
    eAVEncVideoFilmContent_VideoOnly = 0,
    eAVEncVideoFilmContent_FilmOnly = 1,
    eAVEncVideoFilmContent_Mixed = 2
  };

  enum eAVEncVideoChromaResolution {
    eAVEncVideoChromaResolution_SameAsSource = 0,
    eAVEncVideoChromaResolution_444 = 1,
    eAVEncVideoChromaResolution_422 = 2,
    eAVEncVideoChromaResolution_420 = 3,
    eAVEncVideoChromaResolution_411 = 4
  };

  enum eAVEncVideoChromaSubsampling {
    eAVEncVideoChromaSubsamplingFormat_SameAsSource = 0,
    eAVEncVideoChromaSubsamplingFormat_ProgressiveChroma = 0x8,
    eAVEncVideoChromaSubsamplingFormat_Horizontally_Cosited = 0x4,
    eAVEncVideoChromaSubsamplingFormat_Vertically_Cosited = 0x2,
    eAVEncVideoChromaSubsamplingFormat_Vertically_AlignedChromaPlanes = 0x1
  };

  enum eAVEncVideoColorPrimaries {
    eAVEncVideoColorPrimaries_SameAsSource = 0,
    eAVEncVideoColorPrimaries_Reserved = 1,
    eAVEncVideoColorPrimaries_BT709 = 2,
    eAVEncVideoColorPrimaries_BT470_2_SysM = 3,
    eAVEncVideoColorPrimaries_BT470_2_SysBG = 4,
    eAVEncVideoColorPrimaries_SMPTE170M = 5,
    eAVEncVideoColorPrimaries_SMPTE240M = 6,
    eAVEncVideoColorPrimaries_EBU3231 = 7,
    eAVEncVideoColorPrimaries_SMPTE_C = 8
  };

  enum eAVEncVideoColorTransferFunction {
    eAVEncVideoColorTransferFunction_SameAsSource = 0,
    eAVEncVideoColorTransferFunction_10 = 1,
    eAVEncVideoColorTransferFunction_18 = 2,
    eAVEncVideoColorTransferFunction_20 = 3,
    eAVEncVideoColorTransferFunction_22 = 4,
    eAVEncVideoColorTransferFunction_22_709 = 5,
    eAVEncVideoColorTransferFunction_22_240M = 6,
    eAVEncVideoColorTransferFunction_22_8bit_sRGB = 7,
    eAVEncVideoColorTransferFunction_28 = 8
  };

  enum eAVEncVideoColorTransferMatrix {
    eAVEncVideoColorTransferMatrix_SameAsSource = 0,
    eAVEncVideoColorTransferMatrix_BT709 = 1,
    eAVEncVideoColorTransferMatrix_BT601 = 2,
    eAVEncVideoColorTransferMatrix_SMPTE240M = 3
  };

  enum eAVEncVideoColorLighting {
    eAVEncVideoColorLighting_SameAsSource = 0,
    eAVEncVideoColorLighting_Unknown = 1,
    eAVEncVideoColorLighting_Bright = 2,
    eAVEncVideoColorLighting_Office = 3,
    eAVEncVideoColorLighting_Dim = 4,
    eAVEncVideoColorLighting_Dark = 5
  };

  enum eAVEncVideoColorNominalRange {
    eAVEncVideoColorNominalRange_SameAsSource = 0,
    eAVEncVideoColorNominalRange_0_255 = 1,
    eAVEncVideoColorNominalRange_16_235 = 2,
    eAVEncVideoColorNominalRange_48_208 = 3
  };

  enum eAVEncInputVideoSystem {
    eAVEncInputVideoSystem_Unspecified = 0,
    eAVEncInputVideoSystem_PAL = 1,
    eAVEncInputVideoSystem_NTSC = 2,
    eAVEncInputVideoSystem_SECAM = 3,
    eAVEncInputVideoSystem_MAC = 4,
    eAVEncInputVideoSystem_HDV = 5,
    eAVEncInputVideoSystem_Component = 6
  };

  enum eAVEncVideoContentType {
    eAVEncVideoContentType_Unknown = 0,
    eAVEncVideoContentType_FixedCameraAngle = 1
  };

  enum eAVEncAdaptiveMode {
    eAVEncAdaptiveMode_None = 0,
    eAVEncAdaptiveMode_Resolution = 1,
    eAVEncAdaptiveMode_FrameRate = 2
  };

  enum eAVScenarioInfo {
    eAVScenarioInfo_Unknown = 0,
    eAVScenarioInfo_DisplayRemoting = 1,
    eAVScenarioInfo_VideoConference = 2,
    eAVScenarioInfo_Archive = 3,
    eAVScenarioInfo_LiveStreaming = 4,
    eAVScenarioInfo_CameraRecord = 5,
    eAVScenarioInfo_DisplayRemotingWithFeatureMap = 6
  };

  enum eVideoEncoderDisplayContentType {
    eVideoEncoderDisplayContent_Unknown = 0,
    eVideoEncoderDisplayContent_FullScreenVideo = 1
  };

  enum eAVEncMuxOutput {
    eAVEncMuxOutputAuto = 0,
    eAVEncMuxOutputPS = 1,
    eAVEncMuxOutputTS = 2
  };

  enum eAVEncAudioDualMono {
    eAVEncAudioDualMono_SameAsInput = 0,
    eAVEncAudioDualMono_Off = 1,
    eAVEncAudioDualMono_On = 2
  };

  enum eAVEncAudioInputContent {
    AVEncAudioInputContent_Unknown =0,
    AVEncAudioInputContent_Voice = 1,
    AVEncAudioInputContent_Music = 2
  };

  enum eAVEncMPVProfile {
    eAVEncMPVProfile_unknown = 0,
    eAVEncMPVProfile_Simple = 1,
    eAVEncMPVProfile_Main = 2,
    eAVEncMPVProfile_High = 3,
    eAVEncMPVProfile_422 = 4
  };

  enum eAVEncMPVLevel {
    eAVEncMPVLevel_Low = 1,
    eAVEncMPVLevel_Main = 2,
    eAVEncMPVLevel_High1440 = 3,
    eAVEncMPVLevel_High = 4
  };

  enum eAVEncH263VProfile {
    eAVEncH263VProfile_Base = 0,
    eAVEncH263VProfile_CompatibilityV2 = 1,
    eAVEncH263VProfile_CompatibilityV1 = 2,
    eAVEncH263VProfile_WirelessV2 = 3,
    eAVEncH263VProfile_WirelessV3 = 4,
    eAVEncH263VProfile_HighCompression = 5,
    eAVEncH263VProfile_Internet = 6,
    eAVEncH263VProfile_Interlace = 7,
    eAVEncH263VProfile_HighLatency = 8
  };

  enum eAVEncH264VProfile {
   eAVEncH264VProfile_unknown = 0,
   eAVEncH264VProfile_Simple = 66,
   eAVEncH264VProfile_Base = 66,
   eAVEncH264VProfile_Main = 77,
   eAVEncH264VProfile_High = 100,
   eAVEncH264VProfile_422 = 122,
   eAVEncH264VProfile_High10 = 110,
   eAVEncH264VProfile_444 = 244,
   eAVEncH264VProfile_Extended = 88,
   eAVEncH264VProfile_ScalableBase = 83,
   eAVEncH264VProfile_ScalableHigh = 86,
   eAVEncH264VProfile_MultiviewHigh = 118,
   eAVEncH264VProfile_StereoHigh = 128,
   eAVEncH264VProfile_ConstrainedBase = 256,
   eAVEncH264VProfile_UCConstrainedHigh = 257,
   eAVEncH264VProfile_UCScalableConstrainedBase = 258,
   eAVEncH264VProfile_UCScalableConstrainedHigh = 259
  };

#define eAVEncH264VProfile_ConstrainedHigh eAVEncH264VProfile_UCConstrainedHigh

  enum eAVEncH265VProfile {
   eAVEncH265VProfile_unknown = 0,
   eAVEncH265VProfile_Main_420_8 = 1,
   eAVEncH265VProfile_Main_420_10 = 2,
   eAVEncH265VProfile_Main_420_12 = 3,
   eAVEncH265VProfile_Main_422_10 = 4,
   eAVEncH265VProfile_Main_422_12 = 5,
   eAVEncH265VProfile_Main_444_8 = 6,
   eAVEncH265VProfile_Main_444_10 = 7,
   eAVEncH265VProfile_Main_444_12 = 8,
   eAVEncH265VProfile_Monochrome_12 = 9,
   eAVEncH265VProfile_Monochrome_16 = 10,
   eAVEncH265VProfile_MainIntra_420_8 = 11,
   eAVEncH265VProfile_MainIntra_420_10 = 12,
   eAVEncH265VProfile_MainIntra_420_12 = 13,
   eAVEncH265VProfile_MainIntra_422_10 = 14,
   eAVEncH265VProfile_MainIntra_422_12 = 15,
   eAVEncH265VProfile_MainIntra_444_8 = 16,
   eAVEncH265VProfile_MainIntra_444_10 = 17,
   eAVEncH265VProfile_MainIntra_444_12 = 18,
   eAVEncH265VProfile_MainIntra_444_16 = 19,
   eAVEncH265VProfile_MainStill_420_8 = 20,
   eAVEncH265VProfile_MainStill_444_8 = 21,
   eAVEncH265VProfile_MainStill_444_16 = 22
  };

  enum eAVEncVP9VProfile {
    eAVEncVP9VProfile_unknown = 0,
    eAVEncVP9VProfile_420_8 = 1,
    eAVEncVP9VProfile_420_10 = 2,
    eAVEncVP9VProfile_420_12 = 3
  };

  enum eAVEncH263PictureType {
    eAVEncH263PictureType_I = 0,
    eAVEncH263PictureType_P,
    eAVEncH263PictureType_B
  };

  enum eAVEncH264PictureType {
    eAVEncH264PictureType_IDR = 0,
    eAVEncH264PictureType_P,
    eAVEncH264PictureType_B
  };

#define AVENC_H263V_LEVELCOUNT 8

  enum eAVEncH263VLevel {
    eAVEncH263VLevel1 = 10,
    eAVEncH263VLevel2 = 20,
    eAVEncH263VLevel3 = 30,
    eAVEncH263VLevel4 = 40,
    eAVEncH263VLevel4_5 = 45,
    eAVEncH263VLevel5 = 50,
    eAVEncH263VLevel6 = 60,
    eAVEncH263VLevel7 = 70
  };

#define AVENC_H264V_LEVELCOUNT 16
#define AVENC_H264V_MAX_MBBITS 3200

  enum eAVEncH264VLevel {
    eAVEncH264VLevel1 = 10,
    eAVEncH264VLevel1_b = 11,
    eAVEncH264VLevel1_1 = 11,
    eAVEncH264VLevel1_2 = 12,
    eAVEncH264VLevel1_3 = 13,
    eAVEncH264VLevel2 = 20,
    eAVEncH264VLevel2_1 = 21,
    eAVEncH264VLevel2_2 = 22,
    eAVEncH264VLevel3 = 30,
    eAVEncH264VLevel3_1 = 31,
    eAVEncH264VLevel3_2 = 32,
    eAVEncH264VLevel4 = 40,
    eAVEncH264VLevel4_1 = 41,
    eAVEncH264VLevel4_2 = 42,
    eAVEncH264VLevel5 = 50,
    eAVEncH264VLevel5_1 = 51,
    eAVEncH264VLevel5_2 = 52
  };

  enum eAVEncH265VLevel {
    eAVEncH265VLevel1 = 30,
    eAVEncH265VLevel2 = 60,
    eAVEncH265VLevel2_1 = 63,
    eAVEncH265VLevel3 = 90,
    eAVEncH265VLevel3_1 = 93,
    eAVEncH265VLevel4 = 120,
    eAVEncH265VLevel4_1 = 123,
    eAVEncH265VLevel5 = 150,
    eAVEncH265VLevel5_1 = 153,
    eAVEncH265VLevel5_2 = 156,
    eAVEncH265VLevel6 = 180,
    eAVEncH265VLevel6_1 = 183,
    eAVEncH265VLevel6_2 = 186
  };

  enum eAVEncMPVFrameFieldMode {
    eAVEncMPVFrameFieldMode_FieldMode = 0,
    eAVEncMPVFrameFieldMode_FrameMode = 1
  };

  enum eAVEncMPVSceneDetection {
    eAVEncMPVSceneDetection_None = 0,
    eAVEncMPVSceneDetection_InsertIPicture = 1,
    eAVEncMPVSceneDetection_StartNewGOP = 2,
    eAVEncMPVSceneDetection_StartNewLocatableGOP = 3
  };

  enum eAVEncMPVScanPattern {
    eAVEncMPVScanPattern_Auto = 0,
    eAVEncMPVScanPattern_ZigZagScan = 1,
    eAVEncMPVScanPattern_AlternateScan = 2
  };

  enum eAVEncMPVQScaleType {
    eAVEncMPVQScaleType_Auto = 0,
    eAVEncMPVQScaleType_Linear = 1,
    eAVEncMPVQScaleType_NonLinear = 2
  };

  enum eAVEncMPVIntraVLCTable {
    eAVEncMPVIntraVLCTable_Auto = 0,
    eAVEncMPVIntraVLCTable_MPEG1 = 1,
    eAVEncMPVIntraVLCTable_Alternate = 2
  };

  enum eAVEncMPALayer {
    eAVEncMPALayer_1 = 1,
    eAVEncMPALayer_2 = 2,
    eAVEncMPALayer_3 = 3
  };

  enum eAVEncMPACodingMode {
    eAVEncMPACodingMode_Mono = 0,
    eAVEncMPACodingMode_Stereo = 1,
    eAVEncMPACodingMode_DualChannel = 2,
    eAVEncMPACodingMode_JointStereo = 3,
    eAVEncMPACodingMode_Surround = 4
  };

  enum eAVEncMPAEmphasisType {
    eAVEncMPAEmphasisType_None = 0,
    eAVEncMPAEmphasisType_50_15 = 1,
    eAVEncMPAEmphasisType_Reserved = 2,
    eAVEncMPAEmphasisType_CCITT_J17 = 3
  };

  enum eAVEncDDService {
    eAVEncDDService_CM = 0,
    eAVEncDDService_ME = 1,
    eAVEncDDService_VI = 2,
    eAVEncDDService_HI = 3,
    eAVEncDDService_D = 4,
    eAVEncDDService_C = 5,
    eAVEncDDService_E = 6,
    eAVEncDDService_VO = 7
  };

  enum eAVEncDDProductionRoomType {
    eAVEncDDProductionRoomType_NotIndicated = 0,
    eAVEncDDProductionRoomType_Large = 1,
    eAVEncDDProductionRoomType_Small = 2
  };

  enum eAVEncDDDynamicRangeCompressionControl {
    eAVEncDDDynamicRangeCompressionControl_None = 0,
    eAVEncDDDynamicRangeCompressionControl_FilmStandard = 1,
    eAVEncDDDynamicRangeCompressionControl_FilmLight = 2,
    eAVEncDDDynamicRangeCompressionControl_MusicStandard = 3,
    eAVEncDDDynamicRangeCompressionControl_MusicLight = 4,
    eAVEncDDDynamicRangeCompressionControl_Speech = 5
  };

  enum eAVEncDDSurroundExMode {
    eAVEncDDSurroundExMode_NotIndicated = 0,
    eAVEncDDSurroundExMode_No = 1,
    eAVEncDDSurroundExMode_Yes = 2
  };

  enum eAVEncDDPreferredStereoDownMixMode {
    eAVEncDDPreferredStereoDownMixMode_LtRt = 0,
    eAVEncDDPreferredStereoDownMixMode_LoRo = 1
  };

  enum eAVEncDDAtoDConverterType {
    eAVEncDDAtoDConverterType_Standard = 0,
    eAVEncDDAtoDConverterType_HDCD = 1
  };

  enum eAVEncDDHeadphoneMode {
    eAVEncDDHeadphoneMode_NotIndicated = 0,
    eAVEncDDHeadphoneMode_NotEncoded = 1,
    eAVEncDDHeadphoneMode_Encoded = 2
  };

  enum eAVDecVideoInputScanType {
    eAVDecVideoInputScan_Unknown = 0,
    eAVDecVideoInputScan_Progressive = 1,
    eAVDecVideoInputScan_Interlaced_UpperFieldFirst = 2,
    eAVDecVideoInputScan_Interlaced_LowerFieldFirst = 3
  };

  enum eAVDecVideoSWPowerLevel {
    eAVDecVideoSWPowerLevel_BatteryLife = 0,
    eAVDecVideoSWPowerLevel_Balanced = 50,
    eAVDecVideoSWPowerLevel_VideoQuality = 100
  };

  enum eAVDecAACDownmixMode {
    eAVDecAACUseISODownmix = 0,
    eAVDecAACUseARIBDownmix = 1
  };

  enum eAVDecHEAACDynamicRangeControl {
    eAVDecHEAACDynamicRangeControl_OFF = 0,
    eAVDecHEAACDynamicRangeControl_ON = 1
  };

  enum eAVDecAudioDualMono {
    eAVDecAudioDualMono_IsNotDualMono = 0,
    eAVDecAudioDualMono_IsDualMono = 1,
    eAVDecAudioDualMono_UnSpecified = 2
  };

  enum eAVDecAudioDualMonoReproMode {
    eAVDecAudioDualMonoReproMode_STEREO = 0,
    eAVDecAudioDualMonoReproMode_LEFT_MONO = 1,
    eAVDecAudioDualMonoReproMode_RIGHT_MONO = 2,
    eAVDecAudioDualMonoReproMode_MIX_MONO = 3
  };

  enum eAVAudioChannelConfig {
    eAVAudioChannelConfig_FRONT_LEFT = 0x1,
    eAVAudioChannelConfig_FRONT_RIGHT = 0x2,
    eAVAudioChannelConfig_FRONT_CENTER = 0x4,
    eAVAudioChannelConfig_LOW_FREQUENCY = 0x8,
    eAVAudioChannelConfig_BACK_LEFT = 0x10,
    eAVAudioChannelConfig_BACK_RIGHT = 0x20,
    eAVAudioChannelConfig_FRONT_LEFT_OF_CENTER = 0x40,
    eAVAudioChannelConfig_FRONT_RIGHT_OF_CENTER = 0x80,
    eAVAudioChannelConfig_BACK_CENTER = 0x100,
    eAVAudioChannelConfig_SIDE_LEFT = 0x200,
    eAVAudioChannelConfig_SIDE_RIGHT = 0x400,
    eAVAudioChannelConfig_TOP_CENTER = 0x800,
    eAVAudioChannelConfig_TOP_FRONT_LEFT = 0x1000,
    eAVAudioChannelConfig_TOP_FRONT_CENTER = 0x2000,
    eAVAudioChannelConfig_TOP_FRONT_RIGHT = 0x4000,
    eAVAudioChannelConfig_TOP_BACK_LEFT = 0x8000,
    eAVAudioChannelConfig_TOP_BACK_CENTER = 0x10000,
    eAVAudioChannelConfig_TOP_BACK_RIGHT = 0x20000
  };

  enum eAVDDSurroundMode {
    eAVDDSurroundMode_NotIndicated = 0,
    eAVDDSurroundMode_No = 1,
    eAVDDSurroundMode_Yes = 2
  };

  enum eAVDecDDOperationalMode {
    eAVDecDDOperationalMode_NONE = 0,
    eAVDecDDOperationalMode_LINE = 1,
    eAVDecDDOperationalMode_RF = 2,
    eAVDecDDOperationalMode_CUSTOM0 = 3,
    eAVDecDDOperationalMode_CUSTOM1 = 4,
    eAVDecDDOperationalMode_PORTABLE8 = 5,
    eAVDecDDOperationalMode_PORTABLE11 = 6,
    eAVDecDDOperationalMode_PORTABLE14 = 7
  };

  enum eAVDecDDMatrixDecodingMode {
    eAVDecDDMatrixDecodingMode_OFF = 0,
    eAVDecDDMatrixDecodingMode_ON = 1,
    eAVDecDDMatrixDecodingMode_AUTO = 2
  };

  enum eAVDecDDStereoDownMixMode {
    eAVDecDDStereoDownMixMode_Auto = 0,
    eAVDecDDStereoDownMixMode_LtRt = 1,
    eAVDecDDStereoDownMixMode_LoRo = 2
  };

  enum eAVDSPLoudnessEqualization {
    eAVDSPLoudnessEqualization_OFF = 0,
    eAVDSPLoudnessEqualization_ON = 1,
    eAVDSPLoudnessEqualization_AUTO = 2
  };

  enum eAVDSPSpeakerFill {
    eAVDSPSpeakerFill_OFF = 0,
    eAVDSPSpeakerFill_ON = 1,
    eAVDSPSpeakerFill_AUTO = 2
  };

  enum eAVEncChromaEncodeMode {
    eAVEncChromaEncodeMode_420,
    eAVEncChromaEncodeMode_444,
    eAVEncChromaEncodeMode_444_v2
  };

DEFINE_CODECAPI_GUID(AVEncCommonFormatConstraint, "57cbb9b8-116f-4951-b40c-c2a035ed8f17", 0x57cbb9b8, 0x116f, 0x4951, 0xb4, 0x0c, 0xc2, 0xa0, 0x35, 0xed, 0x8f, 0x17)
DEFINE_CODECAPI_GUID(GUID_AVEncCommonFormatUnSpecified, "af46a35a-6024-4525-a48a-094b97f5b3c2", 0xaf46a35a, 0x6024, 0x4525, 0xa4, 0x8a, 0x09, 0x4b, 0x97, 0xf5, 0xb3, 0xc2)
DEFINE_CODECAPI_GUID(GUID_AVEncCommonFormatDVD_V, "cc9598c4-e7fe-451d-b1ca-761bc840b7f3", 0xcc9598c4, 0xe7fe, 0x451d, 0xb1, 0xca, 0x76, 0x1b, 0xc8, 0x40, 0xb7, 0xf3)
DEFINE_CODECAPI_GUID(GUID_AVEncCommonFormatDVD_DashVR, "e55199d6-044c-4dae-a488-531ed306235b", 0xe55199d6, 0x044c, 0x4dae, 0xa4, 0x88, 0x53, 0x1e, 0xd3, 0x06, 0x23, 0x5b)
DEFINE_CODECAPI_GUID(GUID_AVEncCommonFormatDVD_PlusVR, "e74c6f2e-ec37-478d-9af4-a5e135b6271c", 0xe74c6f2e, 0xec37, 0x478d, 0x9a, 0xf4, 0xa5, 0xe1, 0x35, 0xb6, 0x27, 0x1c)
DEFINE_CODECAPI_GUID(GUID_AVEncCommonFormatVCD, "95035bf7-9d90-40ff-ad5c-5cf8cf71ca1d", 0x95035bf7, 0x9d90, 0x40ff, 0xad, 0x5c, 0x5c, 0xf8, 0xcf, 0x71, 0xca, 0x1d)
DEFINE_CODECAPI_GUID(GUID_AVEncCommonFormatSVCD, "51d85818-8220-448c-8066-d69bed16c9ad", 0x51d85818, 0x8220, 0x448c, 0x80, 0x66, 0xd6, 0x9b, 0xed, 0x16, 0xc9, 0xad)
DEFINE_CODECAPI_GUID(GUID_AVEncCommonFormatATSC, "8d7b897c-a019-4670-aa76-2edcac7ac296", 0x8d7b897c, 0xa019, 0x4670, 0xaa, 0x76, 0x2e, 0xdc, 0xac, 0x7a, 0xc2, 0x96)
DEFINE_CODECAPI_GUID(GUID_AVEncCommonFormatDVB, "71830d8f-6c33-430d-844b-c2705baae6db", 0x71830d8f, 0x6c33, 0x430d, 0x84, 0x4b, 0xc2, 0x70, 0x5b, 0xaa, 0xe6, 0xdb)
DEFINE_CODECAPI_GUID(GUID_AVEncCommonFormatMP3, "349733cd-eb08-4dc2-8197-e49835ef828b", 0x349733cd, 0xeb08, 0x4dc2, 0x81, 0x97, 0xe4, 0x98, 0x35, 0xef, 0x82, 0x8b)
DEFINE_CODECAPI_GUID(GUID_AVEncCommonFormatHighMAT, "1eabe760-fb2b-4928-90d1-78db88eee889", 0x1eabe760, 0xfb2b, 0x4928, 0x90, 0xd1, 0x78, 0xdb, 0x88, 0xee, 0xe8, 0x89)
DEFINE_CODECAPI_GUID(GUID_AVEncCommonFormatHighMPV, "a2d25db8-b8f9-42c2-8bc7-0b93cf604788", 0xa2d25db8, 0xb8f9, 0x42c2, 0x8b, 0xc7, 0x0b, 0x93, 0xcf, 0x60, 0x47, 0x88)
DEFINE_CODECAPI_GUID(AVEncCodecType, "08af4ac1-f3f2-4c74-9dcf-37f2ec79f826", 0x08af4ac1, 0xf3f2, 0x4c74, 0x9d, 0xcf, 0x37, 0xf2, 0xec, 0x79, 0xf8, 0x26)
DEFINE_CODECAPI_GUID(GUID_AVEncMPEG1Video, "c8dafefe-da1e-4774-b27d-11830c16b1fe", 0xc8dafefe, 0xda1e, 0x4774, 0xb2, 0x7d, 0x11, 0x83, 0x0c, 0x16, 0xb1, 0xfe)
DEFINE_CODECAPI_GUID(GUID_AVEncMPEG2Video, "046dc19a-6677-4aaa-a31d-c1ab716f4560", 0x046dc19a, 0x6677, 0x4aaa, 0xa3, 0x1d, 0xc1, 0xab, 0x71, 0x6f, 0x45, 0x60)
DEFINE_CODECAPI_GUID(GUID_AVEncMPEG1Audio, "d4dd1362-cd4a-4cd6-8138-b94db4542b04", 0xd4dd1362, 0xcd4a, 0x4cd6, 0x81, 0x38, 0xb9, 0x4d, 0xb4, 0x54, 0x2b, 0x04)
DEFINE_CODECAPI_GUID(GUID_AVEncMPEG2Audio, "ee4cbb1f-9c3f-4770-92b5-fcb7c2a8d381", 0xee4cbb1f, 0x9c3f, 0x4770, 0x92, 0xb5, 0xfc, 0xb7, 0xc2, 0xa8, 0xd3, 0x81)
DEFINE_CODECAPI_GUID(GUID_AVEncWMV, "4e0fef9b-1d43-41bd-b8bd-4d7bf7457a2a", 0x4e0fef9b, 0x1d43, 0x41bd, 0xb8, 0xbd, 0x4d, 0x7b, 0xf7, 0x45, 0x7a, 0x2a)
DEFINE_CODECAPI_GUID(GUID_AVEndMPEG4Video, "dd37b12a-9503-4f8b-b8d0-324a00c0a1cf", 0xdd37b12a, 0x9503, 0x4f8b, 0xb8, 0xd0, 0x32, 0x4a, 0x00, 0xc0, 0xa1, 0xcf)
DEFINE_CODECAPI_GUID(GUID_AVEncH264Video, "95044eab-31b3-47de-8e75-38a42bb03e28", 0x95044eab, 0x31b3, 0x47de, 0x8e, 0x75, 0x38, 0xa4, 0x2b, 0xb0, 0x3e, 0x28)
DEFINE_CODECAPI_GUID(GUID_AVEncDV, "09b769c7-3329-44fb-8954-fa30937d3d5a", 0x09b769c7, 0x3329, 0x44fb, 0x89, 0x54, 0xfa, 0x30, 0x93, 0x7d, 0x3d, 0x5a)
DEFINE_CODECAPI_GUID(GUID_AVEncWMAPro, "1955f90c-33f7-4a68-ab81-53f5657125c4", 0x1955f90c, 0x33f7, 0x4a68, 0xab, 0x81, 0x53, 0xf5, 0x65, 0x71, 0x25, 0xc4)
DEFINE_CODECAPI_GUID(GUID_AVEncWMALossless, "55ca7265-23d8-4761-9031-b74fbe12f4c1", 0x55ca7265, 0x23d8, 0x4761, 0x90, 0x31, 0xb7, 0x4f, 0xbe, 0x12, 0xf4, 0xc1)
DEFINE_CODECAPI_GUID(GUID_AVEncWMAVoice, "13ed18cb-50e8-4276-a288-a6aa228382d9", 0x13ed18cb, 0x50e8, 0x4276, 0xa2, 0x88, 0xa6, 0xaa, 0x22, 0x83, 0x82, 0xd9)
DEFINE_CODECAPI_GUID(GUID_AVEncDolbyDigitalPro, "f5be76cc-0ff8-40eb-9cb1-bba94004d44f", 0xf5be76cc, 0x0ff8, 0x40eb, 0x9c, 0xb1, 0xbb, 0xa9, 0x40, 0x04, 0xd4, 0x4f)
DEFINE_CODECAPI_GUID(GUID_AVEncDolbyDigitalConsumer, "c1a7bf6c-0059-4bfa-94ef-ef747a768d52", 0xc1a7bf6c, 0x0059, 0x4bfa, 0x94, 0xef, 0xef, 0x74, 0x7a, 0x76, 0x8d, 0x52)
DEFINE_CODECAPI_GUID(GUID_AVEncDolbyDigitalPlus, "698d1b80-f7dd-415c-971c-42492a2056c6", 0x698d1b80, 0xf7dd, 0x415c, 0x97, 0x1c, 0x42, 0x49, 0x2a, 0x20, 0x56, 0xc6)
DEFINE_CODECAPI_GUID(GUID_AVEncDTSHD, "2052e630-469d-4bfb-80ca-1d656e7e918f", 0x2052e630, 0x469d, 0x4bfb, 0x80, 0xca, 0x1d, 0x65, 0x6e, 0x7e, 0x91, 0x8f)
DEFINE_CODECAPI_GUID(GUID_AVEncDTS, "45fbcaa2-5e6e-4ab0-8893-5903bee93acf", 0x45fbcaa2, 0x5e6e, 0x4ab0, 0x88, 0x93, 0x59, 0x03, 0xbe, 0xe9, 0x3a, 0xcf)
DEFINE_CODECAPI_GUID(GUID_AVEncMLP, "05f73e29-f0d1-431e-a41c-a47432ec5a66", 0x05f73e29, 0xf0d1, 0x431e, 0xa4, 0x1c, 0xa4, 0x74, 0x32, 0xec, 0x5a, 0x66)
DEFINE_CODECAPI_GUID(GUID_AVEncPCM, "844be7f4-26cf-4779-b386-cc05d187990c", 0x844be7f4, 0x26cf, 0x4779, 0xb3, 0x86, 0xcc, 0x05, 0xd1, 0x87, 0x99, 0x0c)
DEFINE_CODECAPI_GUID(GUID_AVEncSDDS, "1dc1b82f-11c8-4c71-b7b6-ee3eb9bc2b94", 0x1dc1b82f, 0x11c8, 0x4c71, 0xb7, 0xb6, 0xee, 0x3e, 0xb9, 0xbc, 0x2b, 0x94)
DEFINE_CODECAPI_GUID(AVEncCommonRateControlMode, "1c0608e9-370c-4710-8a58-cb6181c42423", 0x1c0608e9, 0x370c, 0x4710, 0x8a, 0x58, 0xcb, 0x61, 0x81, 0xc4, 0x24, 0x23)
DEFINE_CODECAPI_GUID(AVEncCommonLowLatency, "9d3ecd55-89e8-490a-970a-0c9548d5a56e", 0x9d3ecd55, 0x89e8, 0x490a, 0x97, 0x0a, 0x0c, 0x95, 0x48, 0xd5, 0xa5, 0x6e)
DEFINE_CODECAPI_GUID(AVEncCommonMultipassMode, "22533d4c-47e1-41b5-9352-a2b7780e7ac4", 0x22533d4c, 0x47e1, 0x41b5, 0x93, 0x52, 0xa2, 0xb7, 0x78, 0x0e, 0x7a, 0xc4)
DEFINE_CODECAPI_GUID(AVEncCommonPassStart, "6a67739f-4eb5-4385-9928-f276a939ef95", 0x6a67739f, 0x4eb5, 0x4385, 0x99, 0x28, 0xf2, 0x76, 0xa9, 0x39, 0xef, 0x95)
DEFINE_CODECAPI_GUID(AVEncCommonPassEnd, "0e3d01bc-c85c-467d-8b60-c41012ee3bf6", 0x0e3d01bc, 0xc85c, 0x467d, 0x8b, 0x60, 0xc4, 0x10, 0x12, 0xee, 0x3b, 0xf6)
DEFINE_CODECAPI_GUID(AVEncCommonRealTime, "143a0ff6-a131-43da-b81e-98fbb8ec378e", 0x143a0ff6, 0xa131, 0x43da, 0xb8, 0x1e, 0x98, 0xfb, 0xb8, 0xec, 0x37, 0x8e)
DEFINE_CODECAPI_GUID(AVEncCommonQuality, "fcbf57a3-7ea5-4b0c-9644-69b40c39c391", 0xfcbf57a3, 0x7ea5, 0x4b0c, 0x96, 0x44, 0x69, 0xb4, 0x0c, 0x39, 0xc3, 0x91)
DEFINE_CODECAPI_GUID(AVEncCommonQualityVsSpeed, "98332df8-03cd-476b-89fa-3f9e442dec9f", 0x98332df8, 0x03cd, 0x476b, 0x89, 0xfa, 0x3f, 0x9e, 0x44, 0x2d, 0xec, 0x9f)
DEFINE_CODECAPI_GUID(AVEncCommonTranscodeEncodingProfile, "6947787c-f508-4ea9-b1e9-a1fe3a49fbc9", 0x6947787c, 0xf508, 0x4ea9, 0xb1, 0xe9, 0xa1, 0xfe, 0x3a, 0x49, 0xfb, 0xc9)
DEFINE_CODECAPI_GUID(AVEncCommonMeanBitRate, "f7222374-2144-4815-b550-a37f8e12ee52", 0xf7222374, 0x2144, 0x4815, 0xb5, 0x50, 0xa3, 0x7f, 0x8e, 0x12, 0xee, 0x52)
DEFINE_CODECAPI_GUID(AVEncCommonMeanBitRateInterval, "bfaa2f0c-cb82-4bc0-8474-f06a8a0d0258", 0xbfaa2f0c, 0xcb82, 0x4bc0, 0x84, 0x74, 0xf0, 0x6a, 0x8a, 0x0d, 0x02, 0x58)
DEFINE_CODECAPI_GUID(AVEncCommonMaxBitRate, "9651eae4-39b9-4ebf-85ef-d7f444ec7465", 0x9651eae4, 0x39b9, 0x4ebf, 0x85, 0xef, 0xd7, 0xf4, 0x44, 0xec, 0x74, 0x65)
DEFINE_CODECAPI_GUID(AVEncCommonMinBitRate, "101405b2-2083-4034-a806-efbeddd7c9ff", 0x101405b2, 0x2083, 0x4034, 0xa8, 0x06, 0xef, 0xbe, 0xdd, 0xd7, 0xc9, 0xff)
DEFINE_CODECAPI_GUID(AVEncCommonBufferSize, "0db96574-b6a4-4c8b-8106-3773de0310cd", 0x0db96574, 0xb6a4, 0x4c8b, 0x81, 0x06, 0x37, 0x73, 0xde, 0x03, 0x10, 0xcd)
DEFINE_CODECAPI_GUID(AVEncCommonBufferInLevel, "d9c5c8db-fc74-4064-94e9-cd19f947ed45", 0xd9c5c8db, 0xfc74, 0x4064, 0x94, 0xe9, 0xcd, 0x19, 0xf9, 0x47, 0xed, 0x45)
DEFINE_CODECAPI_GUID(AVEncCommonBufferOutLevel, "ccae7f49-d0bc-4e3d-a57e-fb5740140069", 0xccae7f49, 0xd0bc, 0x4e3d, 0xa5, 0x7e, 0xfb, 0x57, 0x40, 0x14, 0x00, 0x69)
DEFINE_CODECAPI_GUID(AVEncCommonStreamEndHandling, "6aad30af-6ba8-4ccc-8fca-18d19beaeb1c", 0x6aad30af, 0x6ba8, 0x4ccc, 0x8f, 0xca, 0x18, 0xd1, 0x9b, 0xea, 0xeb, 0x1c)
DEFINE_CODECAPI_GUID(AVEncStatCommonCompletedPasses, "3e5de533-9df7-438c-854f-9f7dd3683d34", 0x3e5de533, 0x9df7, 0x438c, 0x85, 0x4f, 0x9f, 0x7d, 0xd3, 0x68, 0x3d, 0x34)
DEFINE_CODECAPI_GUID(AVEncVideoOutputFrameRate, "ea85e7c3-9567-4d99-87c4-02c1c278ca7c", 0xea85e7c3, 0x9567, 0x4d99, 0x87, 0xc4, 0x02, 0xc1, 0xc2, 0x78, 0xca, 0x7c)
DEFINE_CODECAPI_GUID(AVEncVideoOutputFrameRateConversion, "8c068bf4-369a-4ba3-82fd-b2518fb3396e", 0x8c068bf4, 0x369a, 0x4ba3, 0x82, 0xfd, 0xb2, 0x51, 0x8f, 0xb3, 0x39, 0x6e)
DEFINE_CODECAPI_GUID(AVEncVideoPixelAspectRatio, "3cdc718f-b3e9-4eb6-a57f-cf1f1b321b87", 0x3cdc718f, 0xb3e9, 0x4eb6, 0xa5, 0x7f, 0xcf, 0x1f, 0x1b, 0x32, 0x1b, 0x87)
DEFINE_CODECAPI_GUID(AVDecVideoAcceleration_MPEG2, "f7db8a2e-4f48-4ee8-ae31-8b6ebe558ae2", 0xf7db8a2e, 0x4f48, 0x4ee8, 0xae, 0x31, 0x8b, 0x6e, 0xbe, 0x55, 0x8a, 0xe2)
DEFINE_CODECAPI_GUID(AVDecVideoAcceleration_H264, "f7db8a2f-4f48-4ee8-ae31-8b6ebe558ae2", 0xf7db8a2f, 0x4f48, 0x4ee8, 0xae, 0x31, 0x8b, 0x6e, 0xbe, 0x55, 0x8a, 0xe2)
DEFINE_CODECAPI_GUID(AVDecVideoAcceleration_VC1, "f7db8a30-4f48-4ee8-ae31-8b6ebe558ae2", 0xf7db8a30, 0x4f48, 0x4ee8, 0xae, 0x31, 0x8b, 0x6e, 0xbe, 0x55, 0x8a, 0xe2)
DEFINE_CODECAPI_GUID(AVDecVideoProcDeinterlaceCSC, "f7db8a31-4f48-4ee8-ae31-8b6ebe558ae2", 0xf7db8a31, 0x4f48, 0x4ee8, 0xae, 0x31, 0x8b, 0x6e, 0xbe, 0x55, 0x8a, 0xe2)
DEFINE_CODECAPI_GUID(AVDecVideoThumbnailGenerationMode, "2efd8eee-1150-4328-9cf5-66dce933fcf4", 0x2efd8eee, 0x1150, 0x4328, 0x9c, 0xf5, 0x66, 0xdc, 0xe9, 0x33, 0xfc, 0xf4)
DEFINE_CODECAPI_GUID(AVDecVideoMaxCodedWidth, "5ae557b8-77af-41f5-9fa6-4db2fe1d4bca", 0x5ae557b8, 0x77af, 0x41f5, 0x9f, 0xa6, 0x4d, 0xb2, 0xfe, 0x1d, 0x4b, 0xca)
DEFINE_CODECAPI_GUID(AVDecVideoMaxCodedHeight, "7262a16a-d2dc-4e75-9ba8-65c0c6d32b13", 0x7262a16a, 0xd2dc, 0x4e75, 0x9b, 0xa8, 0x65, 0xc0, 0xc6, 0xd3, 0x2b, 0x13)
DEFINE_CODECAPI_GUID(AVDecNumWorkerThreads, "9561c3e8-ea9e-4435-9b1e-a93e691894d8", 0x9561c3e8, 0xea9e, 0x4435, 0x9b, 0x1e, 0xa9, 0x3e, 0x69, 0x18, 0x94, 0xd8)
DEFINE_CODECAPI_GUID(AVDecSoftwareDynamicFormatChange, "862e2f0a-507b-47ff-af47-01e2624298b7", 0x862e2f0a, 0x507b, 0x47ff, 0xaf, 0x47, 0x1, 0xe2, 0x62, 0x42, 0x98, 0xb7)
DEFINE_CODECAPI_GUID(AVDecDisableVideoPostProcessing, "f8749193-667a-4f2c-a9e8-5d4af924f08f", 0xf8749193, 0x667a, 0x4f2c, 0xa9, 0xe8, 0x5d, 0x4a, 0xf9, 0x24, 0xf0, 0x8f);
DEFINE_CODECAPI_GUID(AVDecVideoDropPicWithMissingRef, "f8226383-14c2-4567-9734-5004e96ff887", 0xf8226383, 0x14c2, 0x4567, 0x97, 0x34, 0x50, 0x4, 0xe9, 0x6f, 0xf8, 0x87)
DEFINE_CODECAPI_GUID(AVDecVideoSoftwareDeinterlaceMode, "0c08d1ce-9ced-4540-bae3-ceb380141109", 0x0c08d1ce, 0x9ced, 0x4540, 0xba, 0xe3, 0xce, 0xb3, 0x80, 0x14, 0x11, 0x09);
DEFINE_CODECAPI_GUID(AVDecVideoFastDecodeMode, "6b529f7d-d3b1-49c6-a999-9ec6911bedbf", 0x6b529f7d, 0xd3b1, 0x49c6, 0xa9, 0x99, 0x9e, 0xc6, 0x91, 0x1b, 0xed, 0xbf);
DEFINE_CODECAPI_GUID(AVLowLatencyMode, "9c27891a-ed7a-40e1-88e8-b22727a024ee", 0x9c27891a, 0xed7a, 0x40e1, 0x88, 0xe8, 0xb2, 0x27, 0x27, 0xa0, 0x24, 0xee)
DEFINE_CODECAPI_GUID(AVDecVideoH264ErrorConcealment, "ececace8-3436-462c-9294-cd7bacd758a9", 0xececace8, 0x3436, 0x462c, 0x92, 0x94, 0xcd, 0x7b, 0xac, 0xd7, 0x58, 0xa9)
DEFINE_CODECAPI_GUID(AVDecVideoMPEG2ErrorConcealment, "9d2bfe18-728d-48d2-b358-bc7e436c6674", 0x9d2bfe18, 0x728d, 0x48d2, 0xb3, 0x58, 0xbc, 0x7e, 0x43, 0x6c, 0x66, 0x74)
DEFINE_CODECAPI_GUID(AVDecVideoCodecType, "434528e5-21f0-46b6-b62c-9b1b6b658cd1", 0x434528e5, 0x21f0, 0x46b6, 0xb6, 0x2c, 0x9b, 0x1b, 0x6b, 0x65, 0x8c, 0xd1);
DEFINE_CODECAPI_GUID(AVDecVideoDXVAMode, "f758f09e-7337-4ae7-8387-73dc2d54e67d", 0xf758f09e, 0x7337, 0x4ae7, 0x83, 0x87, 0x73, 0xdc, 0x2d, 0x54, 0xe6, 0x7d);
DEFINE_CODECAPI_GUID(AVDecVideoDXVABusEncryption, "42153c8b-fd0b-4765-a462-ddd9e8bcc388", 0x42153c8b, 0xfd0b, 0x4765, 0xa4, 0x62, 0xdd, 0xd9, 0xe8, 0xbc, 0xc3, 0x88);
DEFINE_CODECAPI_GUID(AVEncVideoForceSourceScanType, "1ef2065f-058a-4765-a4fc-8a864c103012", 0x1ef2065f, 0x058a, 0x4765, 0xa4, 0xfc, 0x8a, 0x86, 0x4c, 0x10, 0x30, 0x12)
DEFINE_CODECAPI_GUID(AVEncVideoNoOfFieldsToEncode, "61e4bbe2-4ee0-40e7-80ab-51ddeebe6291", 0x61e4bbe2, 0x4ee0, 0x40e7, 0x80, 0xab, 0x51, 0xdd, 0xee, 0xbe, 0x62, 0x91)
DEFINE_CODECAPI_GUID(AVEncVideoNoOfFieldsToSkip, "a97e1240-1427-4c16-a7f7-3dcfd8ba4cc5", 0xa97e1240, 0x1427, 0x4c16, 0xa7, 0xf7, 0x3d, 0xcf, 0xd8, 0xba, 0x4c, 0xc5)
DEFINE_CODECAPI_GUID(AVEncVideoEncodeDimension, "1074df28-7e0f-47a4-a453-cdd73870f5ce", 0x1074df28, 0x7e0f, 0x47a4, 0xa4, 0x53, 0xcd, 0xd7, 0x38, 0x70, 0xf5, 0xce)
DEFINE_CODECAPI_GUID(AVEncVideoEncodeOffsetOrigin, "6bc098fe-a71a-4454-852e-4d2ddeb2cd24", 0x6bc098fe, 0xa71a, 0x4454, 0x85, 0x2e, 0x4d, 0x2d, 0xde, 0xb2, 0xcd, 0x24)
DEFINE_CODECAPI_GUID(AVEncVideoDisplayDimension, "de053668-f4ec-47a9-86d0-836770f0c1d5", 0xde053668, 0xf4ec, 0x47a9, 0x86, 0xd0, 0x83, 0x67, 0x70, 0xf0, 0xc1, 0xd5)
DEFINE_CODECAPI_GUID(AVEncVideoOutputScanType, "460b5576-842e-49ab-a62d-b36f7312c9db", 0x460b5576, 0x842e, 0x49ab, 0xa6, 0x2d, 0xb3, 0x6f, 0x73, 0x12, 0xc9, 0xdb)
DEFINE_CODECAPI_GUID(AVEncVideoInverseTelecineEnable, "2ea9098b-e76d-4ccd-a030-d3b889c1b64c", 0x2ea9098b, 0xe76d, 0x4ccd, 0xa0, 0x30, 0xd3, 0xb8, 0x89, 0xc1, 0xb6, 0x4c)
DEFINE_CODECAPI_GUID(AVEncVideoInverseTelecineThreshold, "40247d84-e895-497f-b44c-b74560acfe27", 0x40247d84, 0xe895, 0x497f, 0xb4, 0x4c, 0xb7, 0x45, 0x60, 0xac, 0xfe, 0x27)
DEFINE_CODECAPI_GUID(AVEncVideoSourceFilmContent, "1791c64b-ccfc-4827-a0ed-2557793b2b1c", 0x1791c64b, 0xccfc, 0x4827, 0xa0, 0xed, 0x25, 0x57, 0x79, 0x3b, 0x2b, 0x1c)
DEFINE_CODECAPI_GUID(AVEncVideoSourceIsBW, "42ffc49b-1812-4fdc-8d24-7054c521e6eb", 0x42ffc49b, 0x1812, 0x4fdc, 0x8d, 0x24, 0x70, 0x54, 0xc5, 0x21, 0xe6, 0xeb)
DEFINE_CODECAPI_GUID(AVEncVideoFieldSwap, "fefd7569-4e0a-49f2-9f2b-360ea48c19a2", 0xfefd7569, 0x4e0a, 0x49f2, 0x9f, 0x2b, 0x36, 0x0e, 0xa4, 0x8c, 0x19, 0xa2)
DEFINE_CODECAPI_GUID(AVEncVideoInputChromaResolution, "bb0cec33-16f1-47b0-8a88-37815bee1739", 0xbb0cec33, 0x16f1, 0x47b0, 0x8a, 0x88, 0x37, 0x81, 0x5b, 0xee, 0x17, 0x39)
DEFINE_CODECAPI_GUID(AVEncVideoOutputChromaResolution, "6097b4c9-7c1d-4e64-bfcc-9e9765318ae7", 0x6097b4c9, 0x7c1d, 0x4e64, 0xbf, 0xcc, 0x9e, 0x97, 0x65, 0x31, 0x8a, 0xe7)
DEFINE_CODECAPI_GUID(AVEncVideoInputChromaSubsampling, "a8e73a39-4435-4ec3-a6ea-98300f4b36f7", 0xa8e73a39, 0x4435, 0x4ec3, 0xa6, 0xea, 0x98, 0x30, 0x0f, 0x4b, 0x36, 0xf7)
DEFINE_CODECAPI_GUID(AVEncVideoOutputChromaSubsampling, "fa561c6c-7d17-44f0-83c9-32ed12e96343", 0xfa561c6c, 0x7d17, 0x44f0, 0x83, 0xc9, 0x32, 0xed, 0x12, 0xe9, 0x63, 0x43)
DEFINE_CODECAPI_GUID(AVEncVideoInputColorPrimaries, "c24d783f-7ce6-4278-90ab-28a4f1e5f86c", 0xc24d783f, 0x7ce6, 0x4278, 0x90, 0xab, 0x28, 0xa4, 0xf1, 0xe5, 0xf8, 0x6c)
DEFINE_CODECAPI_GUID(AVEncVideoOutputColorPrimaries, "be95907c-9d04-4921-8985-a6d6d87d1a6c", 0xbe95907c, 0x9d04, 0x4921, 0x89, 0x85, 0xa6, 0xd6, 0xd8, 0x7d, 0x1a, 0x6c)
DEFINE_CODECAPI_GUID(AVEncVideoInputColorTransferFunction, "8c056111-a9c3-4b08-a0a0-ce13f8a27c75", 0x8c056111, 0xa9c3, 0x4b08, 0xa0, 0xa0, 0xce, 0x13, 0xf8, 0xa2, 0x7c, 0x75)
DEFINE_CODECAPI_GUID(AVEncVideoOutputColorTransferFunction, "4a7f884a-ea11-460d-bf57-b88bc75900de", 0x4a7f884a, 0xea11, 0x460d, 0xbf, 0x57, 0xb8, 0x8b, 0xc7, 0x59, 0x00, 0xde)
DEFINE_CODECAPI_GUID(AVEncVideoInputColorTransferMatrix, "52ed68b9-72d5-4089-958d-f5405d55081c", 0x52ed68b9, 0x72d5, 0x4089, 0x95, 0x8d, 0xf5, 0x40, 0x5d, 0x55, 0x08, 0x1c)
DEFINE_CODECAPI_GUID(AVEncVideoOutputColorTransferMatrix, "a9b90444-af40-4310-8fbe-ed6d933f892b", 0xa9b90444, 0xaf40, 0x4310, 0x8f, 0xbe, 0xed, 0x6d, 0x93, 0x3f, 0x89, 0x2b)
DEFINE_CODECAPI_GUID(AVEncVideoInputColorLighting, "46a99549-0015-4a45-9c30-1d5cfa258316", 0x46a99549, 0x0015, 0x4a45, 0x9c, 0x30, 0x1d, 0x5c, 0xfa, 0x25, 0x83, 0x16)
DEFINE_CODECAPI_GUID(AVEncVideoOutputColorLighting, "0e5aaac6-ace6-4c5c-998e-1a8c9c6c0f89", 0x0e5aaac6, 0xace6, 0x4c5c, 0x99, 0x8e, 0x1a, 0x8c, 0x9c, 0x6c, 0x0f, 0x89)
DEFINE_CODECAPI_GUID(AVEncVideoInputColorNominalRange, "16cf25c6-a2a6-48e9-ae80-21aec41d427e", 0x16cf25c6, 0xa2a6, 0x48e9, 0xae, 0x80, 0x21, 0xae, 0xc4, 0x1d, 0x42, 0x7e)
DEFINE_CODECAPI_GUID(AVEncVideoOutputColorNominalRange, "972835ed-87b5-4e95-9500-c73958566e54", 0x972835ed, 0x87b5, 0x4e95, 0x95, 0x00, 0xc7, 0x39, 0x58, 0x56, 0x6e, 0x54)
DEFINE_CODECAPI_GUID(AVEncInputVideoSystem, "bede146d-b616-4dc7-92b2-f5d9fa9298f7", 0xbede146d, 0xb616, 0x4dc7, 0x92, 0xb2, 0xf5, 0xd9, 0xfa, 0x92, 0x98, 0xf7)
DEFINE_CODECAPI_GUID(AVEncVideoHeaderDropFrame, "6ed9e124-7925-43fe-971b-e019f62222b4", 0x6ed9e124, 0x7925, 0x43fe, 0x97, 0x1b, 0xe0, 0x19, 0xf6, 0x22, 0x22, 0xb4)
DEFINE_CODECAPI_GUID(AVEncVideoHeaderHours, "2acc7702-e2da-4158-bf9b-88880129d740", 0x2acc7702, 0xe2da, 0x4158, 0xbf, 0x9b, 0x88, 0x88, 0x01, 0x29, 0xd7, 0x40)
DEFINE_CODECAPI_GUID(AVEncVideoHeaderMinutes, "dc1a99ce-0307-408b-880b-b8348ee8ca7f", 0xdc1a99ce, 0x0307, 0x408b, 0x88, 0x0b, 0xb8, 0x34, 0x8e, 0xe8, 0xca, 0x7f)
DEFINE_CODECAPI_GUID(AVEncVideoHeaderSeconds, "4a2e1a05-a780-4f58-8120-9a449d69656b", 0x4a2e1a05, 0xa780, 0x4f58, 0x81, 0x20, 0x9a, 0x44, 0x9d, 0x69, 0x65, 0x6b)
DEFINE_CODECAPI_GUID(AVEncVideoHeaderFrames, "afd5f567-5c1b-4adc-bdaf-735610381436", 0xafd5f567, 0x5c1b, 0x4adc, 0xbd, 0xaf, 0x73, 0x56, 0x10, 0x38, 0x14, 0x36)
DEFINE_CODECAPI_GUID(AVEncVideoDefaultUpperFieldDominant, "810167c4-0bc1-47ca-8fc2-57055a1474a5", 0x810167c4, 0x0bc1, 0x47ca, 0x8f, 0xc2, 0x57, 0x05, 0x5a, 0x14, 0x74, 0xa5)
DEFINE_CODECAPI_GUID(AVEncVideoCBRMotionTradeoff, "0d49451e-18d5-4367-a4ef-3240df1693c4", 0x0d49451e, 0x18d5, 0x4367, 0xa4, 0xef, 0x32, 0x40, 0xdf, 0x16, 0x93, 0xc4)
DEFINE_CODECAPI_GUID(AVEncVideoCodedVideoAccessUnitSize, "b4b10c15-14a7-4ce8-b173-dc90a0b4fcdb", 0xb4b10c15, 0x14a7, 0x4ce8, 0xb1, 0x73, 0xdc, 0x90, 0xa0, 0xb4, 0xfc, 0xdb)
DEFINE_CODECAPI_GUID(AVEncVideoMaxKeyframeDistance, "2987123a-ba93-4704-b489-ec1e5f25292c", 0x2987123a, 0xba93, 0x4704, 0xb4, 0x89, 0xec, 0x1e, 0x5f, 0x25, 0x29, 0x2c)
DEFINE_CODECAPI_GUID(AVEncH264CABACEnable, "ee6cad62-d305-4248-a50e-e1b255f7caf8", 0xee6cad62, 0xd305, 0x4248, 0xa5, 0xe, 0xe1, 0xb2, 0x55, 0xf7, 0xca, 0xf8)
DEFINE_CODECAPI_GUID(AVEncVideoContentType, "66117aca-eb77-459d-930c-a48d9d0683fc", 0x66117aca, 0xeb77, 0x459d, 0x93, 0xc, 0xa4, 0x8d, 0x9d, 0x6, 0x83, 0xfc)
DEFINE_CODECAPI_GUID(AVEncNumWorkerThreads, "b0c8bf60-16f7-4951-a30b-1db1609293d6", 0xb0c8bf60, 0x16f7, 0x4951, 0xa3, 0xb, 0x1d, 0xb1, 0x60, 0x92, 0x93, 0xd6)
DEFINE_CODECAPI_GUID(AVEncVideoEncodeQP, "2cb5696b-23fb-4ce1-a0f9-ef5b90fd55ca", 0x2cb5696b, 0x23fb, 0x4ce1, 0xa0, 0xf9, 0xef, 0x5b, 0x90, 0xfd, 0x55, 0xca)
DEFINE_CODECAPI_GUID(AVEncVideoMinQP, "0ee22c6a-a37c-4568-b5f1-9d4c2b3ab886", 0xee22c6a, 0xa37c, 0x4568,  0xb5, 0xf1, 0x9d, 0x4c, 0x2b, 0x3a, 0xb8, 0x86)
DEFINE_CODECAPI_GUID(AVEncVideoForceKeyFrame, "398c1b98-8353-475a-9ef2-8f265d260345", 0x398c1b98, 0x8353, 0x475a, 0x9e, 0xf2, 0x8f, 0x26, 0x5d, 0x26, 0x3, 0x45)
DEFINE_CODECAPI_GUID(AVEncH264SPSID, "50f38f51-2b79-40e3-b39c-7e9fa0770501", 0x50f38f51, 0x2b79, 0x40e3, 0xb3, 0x9c, 0x7e, 0x9f, 0xa0, 0x77, 0x5, 0x1)
DEFINE_CODECAPI_GUID(AVEncH264PPSID, "bfe29ec2-056c-4d68-a38d-ae5944c8582e", 0xbfe29ec2, 0x56c, 0x4d68, 0xa3, 0x8d, 0xae, 0x59, 0x44, 0xc8, 0x58, 0x2e)
DEFINE_CODECAPI_GUID(AVEncAdaptiveMode, "4419b185-da1f-4f53-bc76-097d0c1efb1e", 0x4419b185, 0xda1f, 0x4f53, 0xbc, 0x76, 0x9, 0x7d, 0xc, 0x1e, 0xfb, 0x1e)
DEFINE_CODECAPI_GUID(AVScenarioInfo, "b28a6e64-3ff9-446a-8a4b-0d7a53413236", 0xb28a6e64, 0x3ff9, 0x446a, 0x8a, 0x4b, 0x0d, 0x7a, 0x53, 0x41, 0x32, 0x36)
DEFINE_CODECAPI_GUID(AVEncMPVGOPSizeMin, "7155cf20-d440-4852-ad0f-9c4abfe37a6a", 0x7155cf20, 0xd440, 0x4852, 0xad, 0x0f, 0x9c, 0x4a, 0xbf, 0xe3, 0x7a, 0x6a)
DEFINE_CODECAPI_GUID(AVEncMPVGOPSizeMax, "fe7de4c4-1936-4fe2-bdf7-1f18ca1d001f", 0xfe7de4c4, 0x1936, 0x4fe2, 0xbd, 0xf7, 0x1f, 0x18, 0xca, 0x1d, 0x00, 0x1f)
DEFINE_CODECAPI_GUID(AVEncVideoMaxCTBSize, "822363ff-cec8-43e5-92fd-e097488485e9", 0x822363ff, 0xcec8, 0x43e5, 0x92, 0xfd, 0xe0, 0x97, 0x48, 0x84, 0x85, 0xe9)
DEFINE_CODECAPI_GUID(AVEncVideoCTBSize, "d47db8b2-e73b-4cb9-8c3e-bd877d06d77b", 0xd47db8b2, 0xe73b, 0x4cb9, 0x8c, 0x3e, 0xbd, 0x87, 0x7d, 0x06, 0xd7, 0x7b)
DEFINE_CODECAPI_GUID(VideoEncoderDisplayContentType, "79b90b27-f4b1-42dc-9dd7-cdaf8135c400", 0x79b90b27, 0xf4b1, 0x42dc, 0x9d, 0xd7, 0xcd, 0xaf, 0x81, 0x35, 0xc4, 0x00)
DEFINE_CODECAPI_GUID(AVEncEnableVideoProcessing, "006f4bf6-0ea3-4d42-8702-b5d8be0f7a92", 0x006f4bf6, 0x0ea3, 0x4d42, 0x87, 0x02, 0xb5, 0xd8, 0xbe, 0x0f, 0x7a, 0x92)
DEFINE_CODECAPI_GUID(AVEncVideoGradualIntraRefresh, "8f347dee-cb0d-49ba-b462-db6927ee2101", 0x8f347dee, 0xcb0d, 0x49ba, 0xb4, 0x62, 0xdb, 0x69, 0x27, 0xee, 0x21, 0x01)
DEFINE_CODECAPI_GUID(GetOPMContext, "2f036c05-4c14-4689-8839-294c6d73e053", 0x2f036c05, 0x4c14, 0x4689, 0x88, 0x39, 0x29, 0x4c, 0x6d, 0x73, 0xe0, 0x53)
DEFINE_CODECAPI_GUID(SetHDCPManagerContext, "6d2d1fc8-3dc9-47eb-a1a2-471c80cd60d0", 0x6d2d1fc8, 0x3dc9, 0x47eb, 0xa1, 0xa2, 0x47, 0x1c, 0x80, 0xcd, 0x60, 0xd0)
DEFINE_CODECAPI_GUID(AVEncVideoMaxTemporalLayers, "9c668cfe-08e1-424a-934e-b764b064802a", 0x9c668cfe, 0x08e1, 0x424a, 0x93, 0x4e, 0xb7, 0x64, 0xb0, 0x64, 0x80, 0x2a)
DEFINE_CODECAPI_GUID(AVEncVideoNumGOPsPerIDR, "83bc5bdb-5b89-4521-8f66-33151c373176", 0x83bc5bdb, 0x5b89, 0x4521, 0x8f, 0x66, 0x33, 0x15, 0x1c, 0x37, 0x31, 0x76)
DEFINE_CODECAPI_GUID(AVEncCommonAllowFrameDrops, "d8477dcb-9598-48e3-8d0c-752bf206093e", 0xd8477dcb, 0x9598, 0x48e3, 0x8d, 0x0c, 0x75, 0x2b, 0xf2, 0x06, 0x09, 0x3e)
DEFINE_CODECAPI_GUID(AVEncVideoIntraLayerPrediction, "d3af46b8-bf47-44bb-a283-69f0b0228ff9", 0xd3af46b8, 0xbf47, 0x44bb, 0xa2, 0x83, 0x69, 0xf0, 0xb0, 0x22, 0x8f, 0xf9)
DEFINE_CODECAPI_GUID(AVEncVideoInstantTemporalUpSwitching, "a3308307-0d96-4ba4-b1f0-b91a5e49df10", 0xa3308307, 0x0d96, 0x4ba4, 0xb1, 0xf0, 0xb9, 0x1a, 0x5e, 0x49, 0xdf, 0x10)
DEFINE_CODECAPI_GUID(AVEncLowPowerEncoder, "b668d582-8bad-4f6a-9141-375a95358b6d", 0xb668d582, 0x8bad, 0x4f6a, 0x91, 0x41, 0x37, 0x5a, 0x95, 0x35, 0x8b, 0x6d)
DEFINE_CODECAPI_GUID(AVEnableInLoopDeblockFilter, "d2e8e399-0623-4bf3-92a8-4d1818529ded", 0xd2e8e399, 0x0623, 0x4bf3, 0x92, 0xa8, 0x4d, 0x18, 0x18, 0x52, 0x9d, 0xed)
DEFINE_CODECAPI_GUID(AVEncVideoSelectLayer, "eb1084f5-6aaa-4914-bb2f-6147227f12e7", 0xeb1084f5, 0x6aaa, 0x4914, 0xbb, 0x2f, 0x61, 0x47, 0x22, 0x7f, 0x12, 0xe7)
DEFINE_CODECAPI_GUID(AVEncVideoTemporalLayerCount, "19caebff-b74d-4cfd-8c27-c2f9d97d5f52", 0x19caebff, 0xb74d, 0x4cfd, 0x8c, 0x27, 0xc2, 0xf9, 0xd9, 0x7d, 0x5f, 0x52)
DEFINE_CODECAPI_GUID(AVEncVideoUsage, "1f636849-5dc1-49f1-b1d8-ce3cf62ea385", 0x1f636849, 0x5dc1, 0x49f1, 0xb1, 0xd8, 0xce, 0x3c, 0xf6, 0x2e, 0xa3, 0x85)
DEFINE_CODECAPI_GUID(AVEncVideoRateControlParams, "87d43767-7645-44ec-b438-d3322fbca29f", 0x87d43767, 0x7645, 0x44ec, 0xb4, 0x38, 0xd3, 0x32, 0x2f, 0xbc, 0xa2, 0x9f)
DEFINE_CODECAPI_GUID(AVEncVideoSupportedControls, "d3f40fdd-77b9-473d-8196-061259e69cff", 0xd3f40fdd, 0x77b9, 0x473d, 0x81, 0x96, 0x06, 0x12, 0x59, 0xe6, 0x9c, 0xff)
DEFINE_CODECAPI_GUID(AVEncVideoEncodeFrameTypeQP, "aa70b610-e03f-450c-ad07-07314e639ce7", 0xaa70b610, 0xe03f, 0x450c, 0xad, 0x07, 0x07, 0x31, 0x4e, 0x63, 0x9c, 0xe7)
DEFINE_CODECAPI_GUID(AVEncSliceControlMode, "e9e782ef-5f18-44c9-a90b-e9c3c2c17b0b", 0xe9e782ef, 0x5f18, 0x44c9, 0xa9, 0x0b, 0xe9, 0xc3, 0xc2, 0xc1, 0x7b, 0x0b)
DEFINE_CODECAPI_GUID(AVEncSliceControlSize, "92f51df3-07a5-4172-aefe-c69ca3b60e35", 0x92f51df3, 0x07a5, 0x4172, 0xae, 0xfe, 0xc6, 0x9c, 0xa3, 0xb6, 0x0e, 0x35)
DEFINE_CODECAPI_GUID(AVEncSliceGenerationMode, "8a6bc67f-9497-4286-b46b-02db8d60edbc", 0x8a6bc67f, 0x9497, 0x4286, 0xb4, 0x6b, 0x02, 0xdb, 0x8d, 0x60, 0xed, 0xbc)
DEFINE_CODECAPI_GUID(AVEncVideoMaxNumRefFrame, "964829ed-94f9-43b4-b74d-ef40944b69a0", 0x964829ed, 0x94f9, 0x43b4, 0xb7, 0x4d, 0xef, 0x40, 0x94, 0x4b, 0x69, 0xa0)
DEFINE_CODECAPI_GUID(AVEncVideoMeanAbsoluteDifference, "e5c0c10f-81a4-422d-8c3f-b474a4581336", 0xe5c0c10f, 0x81a4, 0x422d, 0x8c, 0x3f, 0xb4, 0x74, 0xa4, 0x58, 0x13, 0x36)
DEFINE_CODECAPI_GUID(AVEncVideoMaxQP, "3daf6f66-a6a7-45e0-a8e5-f2743f46a3a2", 0x3daf6f66, 0xa6a7, 0x45e0, 0xa8, 0xe5, 0xf2, 0x74, 0x3f, 0x46, 0xa3, 0xa2)
DEFINE_CODECAPI_GUID(AVEncVideoLTRBufferControl, "a4a0e93d-4cbc-444c-89f4-826d310e92a7", 0xa4a0e93d, 0x4cbc, 0x444c, 0x89, 0xf4, 0x82, 0x6d, 0x31, 0x0e, 0x92, 0xa7)
DEFINE_CODECAPI_GUID(AVEncVideoMarkLTRFrame, "e42f4748-a06d-4ef9-8cea-3d05fde3bd3b", 0xe42f4748, 0xa06d, 0x4ef9, 0x8c, 0xea, 0x3d, 0x05, 0xfd, 0xe3, 0xbd, 0x3b)
DEFINE_CODECAPI_GUID(AVEncVideoUseLTRFrame, "00752db8-55f7-4f80-895b-27639195f2ad", 0x00752db8, 0x55f7, 0x4f80, 0x89, 0x5b, 0x27, 0x63, 0x91, 0x95, 0xf2, 0xad)
DEFINE_CODECAPI_GUID(AVEncVideoROIEnabled, "d74f7f18-44dd-4b85-aba3-05d9f42a8280", 0xd74f7f18, 0x44dd, 0x4b85, 0xab, 0xa3, 0x5, 0xd9, 0xf4, 0x2a, 0x82, 0x80)
DEFINE_CODECAPI_GUID(AVEncVideoDirtyRectEnabled, "8acb8fdd-5e0c-4c66-8729-b8f629ab04fb", 0x8acb8fdd, 0x5e0c, 0x4c66, 0x87, 0x29, 0xb8, 0xf6, 0x29, 0xab, 0x04, 0xfb)
DEFINE_CODECAPI_GUID(AVEncMaxFrameRate, "b98e1b31-19fa-4d4f-9931-d6a5b8aab93c", 0xb98e1b31, 0x19fa, 0x4d4f, 0x99, 0x31, 0xd6, 0xa5, 0xb8, 0xaa, 0xb9, 0x3c)
DEFINE_CODECAPI_GUID(AVEncMuxOutputStreamType, "cedd9e8f-34d3-44db-a1d8-f81520254f3e", 0xcedd9e8f, 0x34d3, 0x44db, 0xa1, 0xd8, 0xf8, 0x15, 0x20, 0x25, 0x4f, 0x3e)
DEFINE_CODECAPI_GUID(AVEncStatVideoOutputFrameRate, "be747849-9ab4-4a63-98fe-f143f04f8ee9", 0xbe747849, 0x9ab4, 0x4a63, 0x98, 0xfe, 0xf1, 0x43, 0xf0, 0x4f, 0x8e, 0xe9)
DEFINE_CODECAPI_GUID(AVEncStatVideoCodedFrames, "d47f8d61-6f5a-4a26-bb9f-cd9518462bcd", 0xd47f8d61, 0x6f5a, 0x4a26, 0xbb, 0x9f, 0xcd, 0x95, 0x18, 0x46, 0x2b, 0xcd)
DEFINE_CODECAPI_GUID(AVEncStatVideoTotalFrames, "fdaa9916-119a-4222-9ad6-3f7cab99cc8b", 0xfdaa9916, 0x119a, 0x4222, 0x9a, 0xd6, 0x3f, 0x7c, 0xab, 0x99, 0xcc, 0x8b)
DEFINE_CODECAPI_GUID(AVEncAudioIntervalToEncode, "866e4b4d-725a-467c-bb01-b496b23b25f9", 0x866e4b4d, 0x725a, 0x467c, 0xbb, 0x01, 0xb4, 0x96, 0xb2, 0x3b, 0x25, 0xf9)
DEFINE_CODECAPI_GUID(AVEncAudioIntervalToSkip, "88c15f94-c38c-4796-a9e8-96e967983f26", 0x88c15f94, 0xc38c, 0x4796, 0xa9, 0xe8, 0x96, 0xe9, 0x67, 0x98, 0x3f, 0x26)
DEFINE_CODECAPI_GUID(AVEncAudioDualMono, "3648126b-a3e8-4329-9b3a-5ce566a43bd3", 0x3648126b, 0xa3e8, 0x4329, 0x9b, 0x3a, 0x5c, 0xe5, 0x66, 0xa4, 0x3b, 0xd3)
DEFINE_CODECAPI_GUID(AVEncAudioMeanBitRate, "921295bb-4fca-4679-aab8-9e2a1d753384", 0x921295bb, 0x4fca, 0x4679, 0xaa, 0xb8, 0x9e, 0x2a, 0x1d, 0x75, 0x33, 0x84)
DEFINE_CODECAPI_GUID(AVEncAudioMapDestChannel0, "bc5d0b60-df6a-4e16-9803-b82007a30c8d", 0xbc5d0b60, 0xdf6a, 0x4e16, 0x98, 0x03, 0xb8, 0x20, 0x07, 0xa3, 0x0c, 0x8d)
DEFINE_CODECAPI_GUID(AVEncAudioMapDestChannel1, "bc5d0b61-df6a-4e16-9803-b82007a30c8d", 0xbc5d0b61, 0xdf6a, 0x4e16, 0x98, 0x03, 0xb8, 0x20, 0x07, 0xa3, 0x0c, 0x8d)
DEFINE_CODECAPI_GUID(AVEncAudioMapDestChannel2, "bc5d0b62-df6a-4e16-9803-b82007a30c8d", 0xbc5d0b62, 0xdf6a, 0x4e16, 0x98, 0x03, 0xb8, 0x20, 0x07, 0xa3, 0x0c, 0x8d)
DEFINE_CODECAPI_GUID(AVEncAudioMapDestChannel3, "bc5d0b63-df6a-4e16-9803-b82007a30c8d", 0xbc5d0b63, 0xdf6a, 0x4e16, 0x98, 0x03, 0xb8, 0x20, 0x07, 0xa3, 0x0c, 0x8d)
DEFINE_CODECAPI_GUID(AVEncAudioMapDestChannel4, "bc5d0b64-df6a-4e16-9803-b82007a30c8d", 0xbc5d0b64, 0xdf6a, 0x4e16, 0x98, 0x03, 0xb8, 0x20, 0x07, 0xa3, 0x0c, 0x8d)
DEFINE_CODECAPI_GUID(AVEncAudioMapDestChannel5, "bc5d0b65-df6a-4e16-9803-b82007a30c8d", 0xbc5d0b65, 0xdf6a, 0x4e16, 0x98, 0x03, 0xb8, 0x20, 0x07, 0xa3, 0x0c, 0x8d)
DEFINE_CODECAPI_GUID(AVEncAudioMapDestChannel6, "bc5d0b66-df6a-4e16-9803-b82007a30c8d", 0xbc5d0b66, 0xdf6a, 0x4e16, 0x98, 0x03, 0xb8, 0x20, 0x07, 0xa3, 0x0c, 0x8d)
DEFINE_CODECAPI_GUID(AVEncAudioMapDestChannel7, "bc5d0b67-df6a-4e16-9803-b82007a30c8d", 0xbc5d0b67, 0xdf6a, 0x4e16, 0x98, 0x03, 0xb8, 0x20, 0x07, 0xa3, 0x0c, 0x8d)
DEFINE_CODECAPI_GUID(AVEncAudioMapDestChannel8, "bc5d0b68-df6a-4e16-9803-b82007a30c8d", 0xbc5d0b68, 0xdf6a, 0x4e16, 0x98, 0x03, 0xb8, 0x20, 0x07, 0xa3, 0x0c, 0x8d)
DEFINE_CODECAPI_GUID(AVEncAudioMapDestChannel9, "bc5d0b69-df6a-4e16-9803-b82007a30c8d", 0xbc5d0b69, 0xdf6a, 0x4e16, 0x98, 0x03, 0xb8, 0x20, 0x07, 0xa3, 0x0c, 0x8d)
DEFINE_CODECAPI_GUID(AVEncAudioMapDestChannel10, "bc5d0b6a-df6a-4e16-9803-b82007a30c8d", 0xbc5d0b6a, 0xdf6a, 0x4e16, 0x98, 0x03, 0xb8, 0x20, 0x07, 0xa3, 0x0c, 0x8d)
DEFINE_CODECAPI_GUID(AVEncAudioMapDestChannel11, "bc5d0b6b-df6a-4e16-9803-b82007a30c8d", 0xbc5d0b6b, 0xdf6a, 0x4e16, 0x98, 0x03, 0xb8, 0x20, 0x07, 0xa3, 0x0c, 0x8d)
DEFINE_CODECAPI_GUID(AVEncAudioMapDestChannel12, "bc5d0b6c-df6a-4e16-9803-b82007a30c8d", 0xbc5d0b6c, 0xdf6a, 0x4e16, 0x98, 0x03, 0xb8, 0x20, 0x07, 0xa3, 0x0c, 0x8d)
DEFINE_CODECAPI_GUID(AVEncAudioMapDestChannel13, "bc5d0b6d-df6a-4e16-9803-b82007a30c8d", 0xbc5d0b6d, 0xdf6a, 0x4e16, 0x98, 0x03, 0xb8, 0x20, 0x07, 0xa3, 0x0c, 0x8d)
DEFINE_CODECAPI_GUID(AVEncAudioMapDestChannel14, "bc5d0b6e-df6a-4e16-9803-b82007a30c8d", 0xbc5d0b6e, 0xdf6a, 0x4e16, 0x98, 0x03, 0xb8, 0x20, 0x07, 0xa3, 0x0c, 0x8d)
DEFINE_CODECAPI_GUID(AVEncAudioMapDestChannel15, "bc5d0b6f-df6a-4e16-9803-b82007a30c8d", 0xbc5d0b6f, 0xdf6a, 0x4e16, 0x98, 0x03, 0xb8, 0x20, 0x07, 0xa3, 0x0c, 0x8d)
DEFINE_CODECAPI_GUID(AVEncAudioInputContent, "3e226c2b-60b9-4a39-b00b-a7b40f70d566", 0x3e226c2b, 0x60b9, 0x4a39, 0xb0, 0x0b, 0xa7, 0xb4, 0x0f, 0x70, 0xd5, 0x66)
DEFINE_CODECAPI_GUID(AVEncStatAudioPeakPCMValue, "dce7fd34-dc00-4c16-821b-35d9eb00fb1a", 0xdce7fd34, 0xdc00, 0x4c16, 0x82, 0x1b, 0x35, 0xd9, 0xeb, 0x00, 0xfb, 0x1a)
DEFINE_CODECAPI_GUID(AVEncStatAudioAveragePCMValue, "979272f8-d17f-4e32-bb73-4e731c68ba2d", 0x979272f8, 0xd17f, 0x4e32, 0xbb, 0x73, 0x4e, 0x73, 0x1c, 0x68, 0xba, 0x2d)
DEFINE_CODECAPI_GUID(AVEncStatAudioAverageBPS, "ca6724db-7059-4351-8b43-f82198826a14", 0xca6724db, 0x7059, 0x4351, 0x8b, 0x43, 0xf8, 0x21, 0x98, 0x82, 0x6a, 0x14)
DEFINE_CODECAPI_GUID(AVEncStatAverageBPS, "ca6724db-7059-4351-8b43-f82198826a14", 0xca6724db, 0x7059, 0x4351, 0x8b, 0x43, 0xf8, 0x21, 0x98, 0x82, 0x6a, 0x14)
DEFINE_CODECAPI_GUID(AVEncStatHardwareProcessorUtilitization, "995dc027-cb95-49e6-b91b-5967753cdcb8", 0x995dc027, 0xcb95, 0x49e6, 0xb9, 0x1b, 0x59, 0x67, 0x75, 0x3c, 0xdc, 0xb8)
DEFINE_CODECAPI_GUID(AVEncStatHardwareBandwidthUtilitization, "0124ba9b-dc41-4826-b45f-18ac01b3d5a8", 0x0124ba9b, 0xdc41, 0x4826, 0xb4, 0x5f, 0x18, 0xac, 0x01, 0xb3, 0xd5, 0xa8)
DEFINE_CODECAPI_GUID(AVEncMPVGOPSize, "95f31b26-95a4-41aa-9303-246a7fc6eef1", 0x95f31b26, 0x95a4, 0x41aa, 0x93, 0x03, 0x24, 0x6a, 0x7f, 0xc6, 0xee, 0xf1)
DEFINE_CODECAPI_GUID(AVEncMPVGOPOpen, "b1d5d4a6-3300-49b1-ae61-a09937ab0e49", 0xb1d5d4a6, 0x3300, 0x49b1, 0xae, 0x61, 0xa0, 0x99, 0x37, 0xab, 0x0e, 0x49)
DEFINE_CODECAPI_GUID(AVEncMPVDefaultBPictureCount, "8d390aac-dc5c-4200-b57f-814d04babab2", 0x8d390aac, 0xdc5c, 0x4200, 0xb5, 0x7f, 0x81, 0x4d, 0x04, 0xba, 0xba, 0xb2)
DEFINE_CODECAPI_GUID(AVEncMPVProfile, "dabb534a-1d99-4284-975a-d90e2239baa1", 0xdabb534a, 0x1d99, 0x4284, 0x97, 0x5a, 0xd9, 0x0e, 0x22, 0x39, 0xba, 0xa1)
DEFINE_CODECAPI_GUID(AVEncMPVLevel, "6ee40c40-a60c-41ef-8f50-37c2249e2cb3", 0x6ee40c40, 0xa60c, 0x41ef, 0x8f, 0x50, 0x37, 0xc2, 0x24, 0x9e, 0x2c, 0xb3)
DEFINE_CODECAPI_GUID(AVEncMPVFrameFieldMode, "acb5de96-7b93-4c2f-8825-b0295fa93bf4", 0xacb5de96, 0x7b93, 0x4c2f, 0x88, 0x25, 0xb0, 0x29, 0x5f, 0xa9, 0x3b, 0xf4)
DEFINE_CODECAPI_GUID(AVEncMPVAddSeqEndCode, "a823178f-57df-4c7a-b8fd-e5ec8887708d", 0xa823178f, 0x57df, 0x4c7a, 0xb8, 0xfd, 0xe5, 0xec, 0x88, 0x87, 0x70, 0x8d)
DEFINE_CODECAPI_GUID(AVEncMPVGOPSInSeq, "993410d4-2691-4192-9978-98dc2603669f", 0x993410d4, 0x2691, 0x4192, 0x99, 0x78, 0x98, 0xdc, 0x26, 0x03, 0x66, 0x9f)
DEFINE_CODECAPI_GUID(AVEncMPVUseConcealmentMotionVectors,  "ec770cf3-6908-4b4b-aa30-7fb986214fea", 0xec770cf3, 0x6908, 0x4b4b, 0xaa, 0x30, 0x7f, 0xb9, 0x86, 0x21, 0x4f, 0xea)
DEFINE_CODECAPI_GUID(AVEncMPVSceneDetection, "552799f1-db4c-405b-8a3a-c93f2d0674dc", 0x552799f1, 0xdb4c, 0x405b, 0x8a, 0x3a, 0xc9, 0x3f, 0x2d, 0x06, 0x74, 0xdc)
DEFINE_CODECAPI_GUID(AVEncMPVGenerateHeaderSeqExt, "d5e78611-082d-4e6b-98af-0f51ab139222", 0xd5e78611, 0x082d, 0x4e6b, 0x98, 0xaf, 0x0f, 0x51, 0xab, 0x13, 0x92, 0x22)
DEFINE_CODECAPI_GUID(AVEncMPVGenerateHeaderSeqDispExt, "6437aa6f-5a3c-4de9-8a16-53d9c4ad326f", 0x6437aa6f, 0x5a3c, 0x4de9, 0x8a, 0x16, 0x53, 0xd9, 0xc4, 0xad, 0x32, 0x6f)
DEFINE_CODECAPI_GUID(AVEncMPVGenerateHeaderPicExt, "1b8464ab-944f-45f0-b74e-3a58dad11f37", 0x1b8464ab, 0x944f, 0x45f0, 0xb7, 0x4e, 0x3a, 0x58, 0xda, 0xd1, 0x1f, 0x37)
DEFINE_CODECAPI_GUID(AVEncMPVGenerateHeaderPicDispExt, "c6412f84-c03f-4f40-a00c-4293df8395bb", 0xc6412f84, 0xc03f, 0x4f40, 0xa0, 0x0c, 0x42, 0x93, 0xdf, 0x83, 0x95, 0xbb)
DEFINE_CODECAPI_GUID(AVEncMPVGenerateHeaderSeqScaleExt, "0722d62f-dd59-4a86-9cd5-644f8e2653d8", 0x0722d62f, 0xdd59, 0x4a86, 0x9c, 0xd5, 0x64, 0x4f, 0x8e, 0x26, 0x53, 0xd8)
DEFINE_CODECAPI_GUID(AVEncMPVScanPattern, "7f8a478e-7bbb-4ae2-b2fc-96d17fc4a2d6", 0x7f8a478e, 0x7bbb, 0x4ae2, 0xb2, 0xfc, 0x96, 0xd1, 0x7f, 0xc4, 0xa2, 0xd6)
DEFINE_CODECAPI_GUID(AVEncMPVIntraDCPrecision, "a0116151-cbc8-4af3-97dc-d00cceb82d79", 0xa0116151, 0xcbc8, 0x4af3, 0x97, 0xdc, 0xd0, 0x0c, 0xce, 0xb8, 0x2d, 0x79)
DEFINE_CODECAPI_GUID(AVEncMPVQScaleType, "2b79ebb7-f484-4af7-bb58-a2a188c5cbbe", 0x2b79ebb7, 0xf484, 0x4af7, 0xbb, 0x58, 0xa2, 0xa1, 0x88, 0xc5, 0xcb, 0xbe)
DEFINE_CODECAPI_GUID(AVEncMPVIntraVLCTable, "a2b83ff5-1a99-405a-af95-c5997d558d3a", 0xa2b83ff5, 0x1a99, 0x405a, 0xaf, 0x95, 0xc5, 0x99, 0x7d, 0x55, 0x8d, 0x3a)
DEFINE_CODECAPI_GUID(AVEncMPVQuantMatrixIntra, "9bea04f3-6621-442c-8ba1-3ac378979698", 0x9bea04f3, 0x6621, 0x442c, 0x8b, 0xa1, 0x3a, 0xc3, 0x78, 0x97, 0x96, 0x98)
DEFINE_CODECAPI_GUID(AVEncMPVQuantMatrixNonIntra, "87f441d8-0997-4beb-a08e-8573d409cf75", 0x87f441d8, 0x0997, 0x4beb, 0xa0, 0x8e, 0x85, 0x73, 0xd4, 0x09, 0xcf, 0x75)
DEFINE_CODECAPI_GUID(AVEncMPVQuantMatrixChromaIntra, "9eb9ecd4-018d-4ffd-8f2d-39e49f07b17a", 0x9eb9ecd4, 0x018d, 0x4ffd, 0x8f, 0x2d, 0x39, 0xe4, 0x9f, 0x07, 0xb1, 0x7a)
DEFINE_CODECAPI_GUID(AVEncMPVQuantMatrixChromaNonIntra, "1415b6b1-362a-4338-ba9a-1ef58703c05b", 0x1415b6b1, 0x362a, 0x4338, 0xba, 0x9a, 0x1e, 0xf5, 0x87, 0x03, 0xc0, 0x5b)
DEFINE_CODECAPI_GUID(AVEncMPALayer, "9d377230-f91b-453d-9ce0-78445414c22d", 0x9d377230, 0xf91b, 0x453d, 0x9c, 0xe0, 0x78, 0x44, 0x54, 0x14, 0xc2, 0x2d)
DEFINE_CODECAPI_GUID(AVEncMPACodingMode, "b16ade03-4b93-43d7-a550-90b4fe224537", 0xb16ade03, 0x4b93, 0x43d7, 0xa5, 0x50, 0x90, 0xb4, 0xfe, 0x22, 0x45, 0x37)
DEFINE_CODECAPI_GUID(AVEncMPACopyright, "a6ae762a-d0a9-4454-b8ef-f2dbeefdd3bd", 0xa6ae762a, 0xd0a9, 0x4454, 0xb8, 0xef, 0xf2, 0xdb, 0xee, 0xfd, 0xd3, 0xbd)
DEFINE_CODECAPI_GUID(AVEncMPAOriginalBitstream, "3cfb7855-9cc9-47ff-b829-b36786c92346", 0x3cfb7855, 0x9cc9, 0x47ff, 0xb8, 0x29, 0xb3, 0x67, 0x86, 0xc9, 0x23, 0x46)
DEFINE_CODECAPI_GUID(AVEncMPAEnableRedundancyProtection, "5e54b09e-b2e7-4973-a89b-0b3650a3beda", 0x5e54b09e, 0xb2e7, 0x4973, 0xa8, 0x9b, 0x0b, 0x36, 0x50, 0xa3, 0xbe, 0xda)
DEFINE_CODECAPI_GUID(AVEncMPAPrivateUserBit, "afa505ce-c1e3-4e3d-851b-61b700e5e6cc", 0xafa505ce, 0xc1e3, 0x4e3d, 0x85, 0x1b, 0x61, 0xb7, 0x00, 0xe5, 0xe6, 0xcc)
DEFINE_CODECAPI_GUID(AVEncMPAEmphasisType, "2d59fcda-bf4e-4ed6-b5df-5b03b36b0a1f", 0x2d59fcda, 0xbf4e, 0x4ed6, 0xb5, 0xdf, 0x5b, 0x03, 0xb3, 0x6b, 0x0a, 0x1f)
DEFINE_CODECAPI_GUID(AVEncDDService, "d2e1bec7-5172-4d2a-a50e-2f3b82b1ddf8", 0xd2e1bec7, 0x5172, 0x4d2a, 0xa5, 0x0e, 0x2f, 0x3b, 0x82, 0xb1, 0xdd, 0xf8)
DEFINE_CODECAPI_GUID(AVEncDDDialogNormalization, "d7055acf-f125-437d-a704-79c79f0404a8", 0xd7055acf, 0xf125, 0x437d, 0xa7, 0x04, 0x79, 0xc7, 0x9f, 0x04, 0x04, 0xa8)
DEFINE_CODECAPI_GUID(AVEncDDCentreDownMixLevel, "e285072c-c958-4a81-afd2-e5e0daf1b148", 0xe285072c, 0xc958, 0x4a81, 0xaf, 0xd2, 0xe5, 0xe0, 0xda, 0xf1, 0xb1, 0x48)
DEFINE_CODECAPI_GUID(AVEncDDSurroundDownMixLevel, "7b20d6e5-0bcf-4273-a487-506b047997e9", 0x7b20d6e5, 0x0bcf, 0x4273, 0xa4, 0x87, 0x50, 0x6b, 0x04, 0x79, 0x97, 0xe9)
DEFINE_CODECAPI_GUID(AVEncDDProductionInfoExists, "b0b7fe5f-b6ab-4f40-964d-8d91f17c19e8", 0xb0b7fe5f, 0xb6ab, 0x4f40, 0x96, 0x4d, 0x8d, 0x91, 0xf1, 0x7c, 0x19, 0xe8)
DEFINE_CODECAPI_GUID(AVEncDDProductionRoomType, "dad7ad60-23d8-4ab7-a284-556986d8a6fe", 0xdad7ad60, 0x23d8, 0x4ab7, 0xa2, 0x84, 0x55, 0x69, 0x86, 0xd8, 0xa6, 0xfe)
DEFINE_CODECAPI_GUID(AVEncDDProductionMixLevel, "301d103a-cbf9-4776-8899-7c15b461ab26", 0x301d103a, 0xcbf9, 0x4776, 0x88, 0x99, 0x7c, 0x15, 0xb4, 0x61, 0xab, 0x26)
DEFINE_CODECAPI_GUID(AVEncDDCopyright, "8694f076-cd75-481d-a5c6-a904dcc828f0", 0x8694f076, 0xcd75, 0x481d, 0xa5, 0xc6, 0xa9, 0x04, 0xdc, 0xc8, 0x28, 0xf0)
DEFINE_CODECAPI_GUID(AVEncDDOriginalBitstream, "966ae800-5bd3-4ff9-95b9-d30566273856", 0x966ae800, 0x5bd3, 0x4ff9, 0x95, 0xb9, 0xd3, 0x05, 0x66, 0x27, 0x38, 0x56)
DEFINE_CODECAPI_GUID(AVEncDDDigitalDeemphasis, "e024a2c2-947c-45ac-87d8-f1030c5c0082", 0xe024a2c2, 0x947c, 0x45ac, 0x87, 0xd8, 0xf1, 0x03, 0x0c, 0x5c, 0x00, 0x82)
DEFINE_CODECAPI_GUID(AVEncDDDCHighPassFilter, "9565239f-861c-4ac8-bfda-e00cb4db8548", 0x9565239f, 0x861c, 0x4ac8, 0xbf, 0xda, 0xe0, 0x0c, 0xb4, 0xdb, 0x85, 0x48)
DEFINE_CODECAPI_GUID(AVEncDDChannelBWLowPassFilter, "e197821d-d2e7-43e2-ad2c-00582f518545", 0xe197821d, 0xd2e7, 0x43e2, 0xad, 0x2c, 0x00, 0x58, 0x2f, 0x51, 0x85, 0x45)
DEFINE_CODECAPI_GUID(AVEncDDLFELowPassFilter, "d3b80f6f-9d15-45e5-91be-019c3fab1f01", 0xd3b80f6f, 0x9d15, 0x45e5, 0x91, 0xbe, 0x01, 0x9c, 0x3f, 0xab, 0x1f, 0x01)
DEFINE_CODECAPI_GUID(AVEncDDSurround90DegreeePhaseShift, "25ecec9d-3553-42c0-bb56-d25792104f80", 0x25ecec9d, 0x3553, 0x42c0, 0xbb, 0x56, 0xd2, 0x57, 0x92, 0x10, 0x4f, 0x80)
DEFINE_CODECAPI_GUID(AVEncDDSurround3dBAttenuation, "4d43b99d-31e2-48b9-bf2e-5cbf1a572784", 0x4d43b99d, 0x31e2, 0x48b9, 0xbf, 0x2e, 0x5c, 0xbf, 0x1a, 0x57, 0x27, 0x84)
DEFINE_CODECAPI_GUID(AVEncDDDynamicRangeCompressionControl, "cfc2ff6d-79b8-4b8d-a8aa-a0c9bd1c2940", 0xcfc2ff6d, 0x79b8, 0x4b8d, 0xa8, 0xaa, 0xa0, 0xc9, 0xbd, 0x1c, 0x29, 0x40)
DEFINE_CODECAPI_GUID(AVEncDDRFPreEmphasisFilter, "21af44c0-244e-4f3d-a2cc-3d3068b2e73f", 0x21af44c0, 0x244e, 0x4f3d, 0xa2, 0xcc, 0x3d, 0x30, 0x68, 0xb2, 0xe7, 0x3f)
DEFINE_CODECAPI_GUID(AVEncDDSurroundExMode, "91607cee-dbdd-4eb6-bca2-aadfafa3dd68", 0x91607cee, 0xdbdd, 0x4eb6, 0xbc, 0xa2, 0xaa, 0xdf, 0xaf, 0xa3, 0xdd, 0x68)
DEFINE_CODECAPI_GUID(AVEncDDPreferredStereoDownMixMode, "7f4e6b31-9185-403d-b0a2-763743e6f063", 0x7f4e6b31, 0x9185, 0x403d, 0xb0, 0xa2, 0x76, 0x37, 0x43, 0xe6, 0xf0, 0x63)
DEFINE_CODECAPI_GUID(AVEncDDLtRtCenterMixLvl_x10, "dca128a2-491f-4600-b2da-76e3344b4197", 0xdca128a2, 0x491f, 0x4600, 0xb2, 0xda, 0x76, 0xe3, 0x34, 0x4b, 0x41, 0x97)
DEFINE_CODECAPI_GUID(AVEncDDLtRtSurroundMixLvl_x10, "212246c7-3d2c-4dfa-bc21-652a9098690d", 0x212246c7, 0x3d2c, 0x4dfa, 0xbc, 0x21, 0x65, 0x2a, 0x90, 0x98, 0x69, 0x0d)
DEFINE_CODECAPI_GUID(AVEncDDLoRoCenterMixLvl_x10, "1cfba222-25b3-4bf4-9bfd-e7111267858c", 0x1cfba222, 0x25b3, 0x4bf4, 0x9b, 0xfd, 0xe7, 0x11, 0x12, 0x67, 0x85, 0x8c)
DEFINE_CODECAPI_GUID(AVEncDDLoRoSurroundMixLvl_x10, "e725cff6-eb56-40c7-8450-2b9367e91555", 0xe725cff6, 0xeb56, 0x40c7, 0x84, 0x50, 0x2b, 0x93, 0x67, 0xe9, 0x15, 0x55)
DEFINE_CODECAPI_GUID(AVEncDDAtoDConverterType, "719f9612-81a1-47e0-9a05-d94ad5fca948", 0x719f9612, 0x81a1, 0x47e0, 0x9a, 0x05, 0xd9, 0x4a, 0xd5, 0xfc, 0xa9, 0x48)
DEFINE_CODECAPI_GUID(AVEncDDHeadphoneMode, "4052dbec-52f5-42f5-9b00-d134b1341b9d", 0x4052dbec, 0x52f5, 0x42f5, 0x9b, 0x00, 0xd1, 0x34, 0xb1, 0x34, 0x1b, 0x9d)
DEFINE_CODECAPI_GUID(AVEncWMVKeyFrameDistance, "5569055e-e268-4771-b83e-9555ea28aed3", 0x5569055e, 0xe268, 0x4771, 0xb8, 0x3e, 0x95, 0x55, 0xea, 0x28, 0xae, 0xd3)
DEFINE_CODECAPI_GUID(AVEncWMVInterlacedEncoding, "e3d00f8a-c6f5-4e14-a588-0ec87a726f9b", 0xe3d00f8a, 0xc6f5, 0x4e14, 0xa5, 0x88, 0x0e, 0xc8, 0x7a, 0x72, 0x6f, 0x9b)
DEFINE_CODECAPI_GUID(AVEncWMVDecoderComplexity, "f32c0dab-f3cb-4217-b79f-8762768b5f67", 0xf32c0dab, 0xf3cb, 0x4217, 0xb7, 0x9f, 0x87, 0x62, 0x76, 0x8b, 0x5f, 0x67)
DEFINE_CODECAPI_GUID(AVEncWMVKeyFrameBufferLevelMarker, "51ff1115-33ac-426c-a1b1-09321bdf96b4", 0x51ff1115, 0x33ac, 0x426c, 0xa1, 0xb1, 0x09, 0x32, 0x1b, 0xdf, 0x96, 0xb4)
DEFINE_CODECAPI_GUID(AVEncWMVProduceDummyFrames, "d669d001-183c-42e3-a3ca-2f4586d2396c", 0xd669d001, 0x183c, 0x42e3, 0xa3, 0xca, 0x2f, 0x45, 0x86, 0xd2, 0x39, 0x6c)
DEFINE_CODECAPI_GUID(AVEncStatWMVCBAvg, "6aa6229f-d602-4b9d-b68c-c1ad78884bef", 0x6aa6229f, 0xd602, 0x4b9d, 0xb6, 0x8c, 0xc1, 0xad, 0x78, 0x88, 0x4b, 0xef)
DEFINE_CODECAPI_GUID(AVEncStatWMVCBMax, "e976bef8-00fe-44b4-b625-8f238bc03499", 0xe976bef8, 0x00fe, 0x44b4, 0xb6, 0x25, 0x8f, 0x23, 0x8b, 0xc0, 0x34, 0x99)
DEFINE_CODECAPI_GUID(AVEncStatWMVDecoderComplexityProfile, "89e69fc3-0f9b-436c-974a-df821227c90d", 0x89e69fc3, 0x0f9b, 0x436c, 0x97, 0x4a, 0xdf, 0x82, 0x12, 0x27, 0xc9, 0x0d)
DEFINE_CODECAPI_GUID(AVEncStatMPVSkippedEmptyFrames, "32195fd3-590d-4812-a7ed-6d639a1f9711", 0x32195fd3, 0x590d, 0x4812, 0xa7, 0xed, 0x6d, 0x63, 0x9a, 0x1f, 0x97, 0x11)
DEFINE_CODECAPI_GUID(AVEncMP12PktzSTDBuffer, "0b751bd0-819e-478c-9435-75208926b377", 0x0b751bd0, 0x819e, 0x478c, 0x94, 0x35, 0x75, 0x20, 0x89, 0x26, 0xb3, 0x77)
DEFINE_CODECAPI_GUID(AVEncMP12PktzStreamID, "c834d038-f5e8-4408-9b60-88f36493fedf", 0xc834d038, 0xf5e8, 0x4408, 0x9b, 0x60, 0x88, 0xf3, 0x64, 0x93, 0xfe, 0xdf)
DEFINE_CODECAPI_GUID(AVEncMP12PktzInitialPTS, "2a4f2065-9a63-4d20-ae22-0a1bc896a315", 0x2a4f2065, 0x9a63, 0x4d20, 0xae, 0x22, 0x0a, 0x1b, 0xc8, 0x96, 0xa3, 0x15)
DEFINE_CODECAPI_GUID(AVEncMP12PktzPacketSize, "ab71347a-1332-4dde-a0e5-ccf7da8a0f22", 0xab71347a, 0x1332, 0x4dde, 0xa0, 0xe5, 0xcc, 0xf7, 0xda, 0x8a, 0x0f, 0x22)
DEFINE_CODECAPI_GUID(AVEncMP12PktzCopyright, "c8f4b0c1-094c-43c7-8e68-a595405a6ef8", 0xc8f4b0c1, 0x094c, 0x43c7, 0x8e, 0x68, 0xa5, 0x95, 0x40, 0x5a, 0x6e, 0xf8)
DEFINE_CODECAPI_GUID(AVEncMP12PktzOriginal, "6b178416-31b9-4964-94cb-6bff866cdf83", 0x6b178416, 0x31b9, 0x4964, 0x94, 0xcb, 0x6b, 0xff, 0x86, 0x6c, 0xdf, 0x83)
DEFINE_CODECAPI_GUID(AVEncMP12MuxPacketOverhead, "e40bd720-3955-4453-acf9-b79132a38fa0", 0xe40bd720, 0x3955, 0x4453, 0xac, 0xf9, 0xb7, 0x91, 0x32, 0xa3, 0x8f, 0xa0)
DEFINE_CODECAPI_GUID(AVEncMP12MuxNumStreams, "f7164a41-dced-4659-a8f2-fb693f2a4cd0", 0xf7164a41, 0xdced, 0x4659, 0xa8, 0xf2, 0xfb, 0x69, 0x3f, 0x2a, 0x4c, 0xd0)
DEFINE_CODECAPI_GUID(AVEncMP12MuxEarliestPTS, "157232b6-f809-474e-9464-a7f93014a817", 0x157232b6, 0xf809, 0x474e, 0x94, 0x64, 0xa7, 0xf9, 0x30, 0x14, 0xa8, 0x17)
DEFINE_CODECAPI_GUID(AVEncMP12MuxLargestPacketSize, "35ceb711-f461-4b92-a4ef-17b6841ed254", 0x35ceb711, 0xf461, 0x4b92, 0xa4, 0xef, 0x17, 0xb6, 0x84, 0x1e, 0xd2, 0x54)
DEFINE_CODECAPI_GUID(AVEncMP12MuxInitialSCR, "3433ad21-1b91-4a0b-b190-2b77063b63a4", 0x3433ad21, 0x1b91, 0x4a0b, 0xb1, 0x90, 0x2b, 0x77, 0x06, 0x3b, 0x63, 0xa4)
DEFINE_CODECAPI_GUID(AVEncMP12MuxMuxRate, "ee047c72-4bdb-4a9d-8e21-41926c823da7", 0xee047c72, 0x4bdb, 0x4a9d, 0x8e, 0x21, 0x41, 0x92, 0x6c, 0x82, 0x3d, 0xa7)
DEFINE_CODECAPI_GUID(AVEncMP12MuxPackSize, "f916053a-1ce8-4faf-aa0b-ba31c80034b8", 0xf916053a, 0x1ce8, 0x4faf, 0xaa, 0x0b, 0xba, 0x31, 0xc8, 0x00, 0x34, 0xb8)
DEFINE_CODECAPI_GUID(AVEncMP12MuxSysSTDBufferBound, "35746903-b545-43e7-bb35-c5e0a7d5093c", 0x35746903, 0xb545, 0x43e7, 0xbb, 0x35, 0xc5, 0xe0, 0xa7, 0xd5, 0x09, 0x3c)
DEFINE_CODECAPI_GUID(AVEncMP12MuxSysRateBound, "05f0428a-ee30-489d-ae28-205c72446710", 0x05f0428a, 0xee30, 0x489d, 0xae, 0x28, 0x20, 0x5c, 0x72, 0x44, 0x67, 0x10)
DEFINE_CODECAPI_GUID(AVEncMP12MuxTargetPacketizer, "d862212a-2015-45dd-9a32-1b3aa88205a0", 0xd862212a, 0x2015, 0x45dd, 0x9a, 0x32, 0x1b, 0x3a, 0xa8, 0x82, 0x05, 0xa0)
DEFINE_CODECAPI_GUID(AVEncMP12MuxSysFixed, "cefb987e-894f-452e-8f89-a4ef8cec063a", 0xcefb987e, 0x894f, 0x452e, 0x8f, 0x89, 0xa4, 0xef, 0x8c, 0xec, 0x06, 0x3a)
DEFINE_CODECAPI_GUID(AVEncMP12MuxSysCSPS, "7952ff45-9c0d-4822-bc82-8ad772e02993", 0x7952ff45, 0x9c0d, 0x4822, 0xbc, 0x82, 0x8a, 0xd7, 0x72, 0xe0, 0x29, 0x93)
DEFINE_CODECAPI_GUID(AVEncMP12MuxSysVideoLock, "b8296408-2430-4d37-a2a1-95b3e435a91d", 0xb8296408, 0x2430, 0x4d37, 0xa2, 0xa1, 0x95, 0xb3, 0xe4, 0x35, 0xa9, 0x1d)
DEFINE_CODECAPI_GUID(AVEncMP12MuxSysAudioLock, "0fbb5752-1d43-47bf-bd79-f2293d8ce337", 0x0fbb5752, 0x1d43, 0x47bf, 0xbd, 0x79, 0xf2, 0x29, 0x3d, 0x8c, 0xe3, 0x37)
DEFINE_CODECAPI_GUID(AVEncMP12MuxDVDNavPacks, "c7607ced-8cf1-4a99-83a1-ee5461be3574", 0xc7607ced, 0x8cf1, 0x4a99, 0x83, 0xa1, 0xee, 0x54, 0x61, 0xbe, 0x35, 0x74)
DEFINE_CODECAPI_GUID(AVDecCommonInputFormat, "e5005239-bd89-4be3-9c0f-5dde317988cc", 0xe5005239, 0xbd89, 0x4be3, 0x9c, 0x0f, 0x5d, 0xde, 0x31, 0x79, 0x88, 0xcc)
DEFINE_CODECAPI_GUID(AVDecCommonOutputFormat, "3c790028-c0ce-4256-b1a2-1b0fc8b1dcdc", 0x3c790028, 0xc0ce, 0x4256, 0xb1, 0xa2, 0x1b, 0x0f, 0xc8, 0xb1, 0xdc, 0xdc)
DEFINE_CODECAPI_GUID(AVDecCommonMeanBitRate, "59488217-007a-4f7a-8e41-5c48b1eac5c6", 0x59488217, 0x007a, 0x4f7a, 0x8e, 0x41, 0x5c, 0x48, 0xb1, 0xea, 0xc5, 0xc6)
DEFINE_CODECAPI_GUID(AVDecCommonMeanBitRateInterval, "0ee437c6-38a7-4c5c-944c-68ab42116b85", 0x0ee437c6, 0x38a7, 0x4c5c, 0x94, 0x4c, 0x68, 0xab, 0x42, 0x11, 0x6b, 0x85)
DEFINE_CODECAPI_GUID(GUID_AVDecAudioOutputFormat_PCM_Stereo_MatrixEncoded, "696e1d30-548f-4036-825f-7026c60011bd", 0x696e1d30, 0x548f, 0x4036, 0x82, 0x5f, 0x70, 0x26, 0xc6, 0x00, 0x11, 0xbd)
DEFINE_CODECAPI_GUID(GUID_AVDecAudioOutputFormat_PCM, "696e1d31-548f-4036-825f-7026c60011bd", 0x696e1d31, 0x548f, 0x4036, 0x82, 0x5f, 0x70, 0x26, 0xc6, 0x00, 0x11, 0xbd)
DEFINE_CODECAPI_GUID(GUID_AVDecAudioOutputFormat_SPDIF_PCM, "696E1D32-548F-4036-825F-7026C60011BD", 0x696e1d32, 0x548f, 0x4036, 0x82, 0x5f, 0x70, 0x26, 0xc6, 0x00, 0x11, 0xbd)
DEFINE_CODECAPI_GUID(GUID_AVDecAudioOutputFormat_SPDIF_Bitstream, "696e1d33-548f-4036-825f-7026c60011bd", 0x696e1d33, 0x548f, 0x4036, 0x82, 0x5f, 0x70, 0x26, 0xc6, 0x00, 0x11, 0xbd)
DEFINE_CODECAPI_GUID(GUID_AVDecAudioOutputFormat_PCM_Headphones, "696e1d34-548f-4036-825f-7026c60011bd", 0x696e1d34, 0x548f, 0x4036, 0x82, 0x5f, 0x70, 0x26, 0xc6, 0x00, 0x11, 0xbd)
DEFINE_CODECAPI_GUID(GUID_AVDecAudioOutputFormat_PCM_Stereo_Auto, "696e1d35-548f-4036-825f-7026c60011bd", 0x696e1d35, 0x548f, 0x4036, 0x82, 0x5f, 0x70, 0x26, 0xc6, 0x00, 0x11, 0xbd)
DEFINE_CODECAPI_GUID(AVDecVideoImageSize, "5ee5747c-6801-4cab-aaf1-6248fa841ba4", 0x5ee5747c, 0x6801, 0x4cab, 0xaa, 0xf1, 0x62, 0x48, 0xfa, 0x84, 0x1b, 0xa4)
DEFINE_CODECAPI_GUID(AVDecVideoPixelAspectRatio, "b0cf8245-f32d-41df-b02c-87bd304d12ab", 0xb0cf8245, 0xf32d, 0x41df, 0xb0, 0x2c, 0x87, 0xbd, 0x30, 0x4d, 0x12, 0xab)
DEFINE_CODECAPI_GUID(AVDecVideoInputScanType, "38477e1f-0ea7-42cd-8cd1-130ced57c580", 0x38477e1f, 0x0ea7, 0x42cd, 0x8c, 0xd1, 0x13, 0x0c, 0xed, 0x57, 0xc5, 0x80)
DEFINE_CODECAPI_GUID(AVDecVideoSWPowerLevel, "fb5d2347-4dd8-4509-aed0-db5fa9aa93f4", 0xfb5d2347, 0x4dd8, 0x4509, 0xae, 0xd0, 0xdb, 0x5f, 0xa9, 0xaa, 0x93, 0xf4)
DEFINE_CODECAPI_GUID(GUID_AVDecAudioInputWMA, "c95e8dcf-4058-4204-8c42-cb24d91e4b9b", 0xc95e8dcf, 0x4058, 0x4204, 0x8c, 0x42, 0xcb, 0x24, 0xd9, 0x1e, 0x4b, 0x9b)
DEFINE_CODECAPI_GUID(GUID_AVDecAudioInputWMAPro, "0128b7c7-da72-4fe3-bef8-5c52e3557704", 0x0128b7c7, 0xda72, 0x4fe3, 0xbe, 0xf8, 0x5c, 0x52, 0xe3, 0x55, 0x77, 0x04)
DEFINE_CODECAPI_GUID(GUID_AVDecAudioInputDolby, "8e4228a0-f000-4e0b-8f54-ab8d24ad61a2", 0x8e4228a0, 0xf000, 0x4e0b, 0x8f, 0x54, 0xab, 0x8d, 0x24, 0xad, 0x61, 0xa2)
DEFINE_CODECAPI_GUID(GUID_AVDecAudioInputDTS, "600bc0ca-6a1f-4e91-b241-1bbeb1cb19e0", 0x600bc0ca, 0x6a1f, 0x4e91, 0xb2, 0x41, 0x1b, 0xbe, 0xb1, 0xcb, 0x19, 0xe0)
DEFINE_CODECAPI_GUID(GUID_AVDecAudioInputPCM, "f2421da5-bbb4-4cd5-a996-933c6b5d1347", 0xf2421da5, 0xbbb4, 0x4cd5, 0xa9, 0x96, 0x93, 0x3c, 0x6b, 0x5d, 0x13, 0x47)
DEFINE_CODECAPI_GUID(GUID_AVDecAudioInputMPEG, "91106f36-02c5-4f75-9719-3b7abf75e1f6", 0x91106f36, 0x02c5, 0x4f75, 0x97, 0x19, 0x3b, 0x7a, 0xbf, 0x75, 0xe1, 0xf6)
DEFINE_CODECAPI_GUID(GUID_AVDecAudioInputAAC, "97df7828-b94a-47e2-a4bc-51194db22a4d", 0x97df7828, 0xb94a, 0x47e2, 0xa4, 0xbc, 0x51, 0x19, 0x4d, 0xb2, 0x2a, 0x4d)
DEFINE_CODECAPI_GUID(GUID_AVDecAudioInputHEAAC, "16efb4aa-330e-4f5c-98a8-cf6ac55cbe60", 0x16efb4aa, 0x330e, 0x4f5c, 0x98, 0xa8, 0xcf, 0x6a, 0xc5, 0x5c, 0xbe, 0x60)
DEFINE_CODECAPI_GUID(GUID_AVDecAudioInputDolbyDigitalPlus, "0803e185-8f5d-47f5-9908-19a5bbc9fe34", 0x0803e185, 0x8f5d, 0x47f5, 0x99, 0x08, 0x19, 0xa5, 0xbb, 0xc9, 0xfe, 0x34)
DEFINE_CODECAPI_GUID(AVDecAACDownmixMode, "01274475-f6bb-4017-b084-81a763c942d4", 0x1274475, 0xf6bb, 0x4017,  0xb0, 0x84, 0x81, 0xa7, 0x63, 0xc9, 0x42, 0xd4)
DEFINE_CODECAPI_GUID(AVDecHEAACDynamicRangeControl, "287c8abe-69a4-4d39-8080-d3d9712178a0", 0x287c8abe, 0x69a4, 0x4d39, 0x80, 0x80, 0xd3, 0xd9, 0x71, 0x21, 0x78, 0xa0);
DEFINE_CODECAPI_GUID(AVDecAudioDualMono,"4a52cda8-30f8-4216-be0f-ba0b2025921d", 0x4a52cda8, 0x30f8, 0x4216, 0xbe, 0x0f, 0xba, 0x0b, 0x20, 0x25, 0x92, 0x1d)
DEFINE_CODECAPI_GUID(AVDecAudioDualMonoReproMode,"a5106186-cc94-4bc9-8cd9-aa2f61f6807e", 0xa5106186, 0xcc94, 0x4bc9, 0x8c, 0xd9, 0xaa, 0x2f, 0x61, 0xf6, 0x80, 0x7e)
DEFINE_CODECAPI_GUID(AVAudioChannelCount, "1d3583c4-1583-474e-b71a-5ee463c198e4", 0x1d3583c4, 0x1583, 0x474e, 0xb7, 0x1a, 0x5e, 0xe4, 0x63, 0xc1, 0x98, 0xe4)
DEFINE_CODECAPI_GUID(AVAudioChannelConfig, "17f89cb3-c38d-4368-9ede-63b94d177f9f", 0x17f89cb3, 0xc38d, 0x4368, 0x9e, 0xde, 0x63, 0xb9, 0x4d, 0x17, 0x7f, 0x9f)
DEFINE_CODECAPI_GUID(AVAudioSampleRate, "971d2723-1acb-42e7-855c-520a4b70a5f2", 0x971d2723, 0x1acb, 0x42e7, 0x85, 0x5c, 0x52, 0x0a, 0x4b, 0x70, 0xa5, 0xf2)
DEFINE_CODECAPI_GUID(AVDDSurroundMode, "99f2f386-98d1-4452-a163-abc78a6eb770", 0x99f2f386, 0x98d1, 0x4452, 0xa1, 0x63, 0xab, 0xc7, 0x8a, 0x6e, 0xb7, 0x70)
DEFINE_CODECAPI_GUID(AVDecDDOperationalMode, "d6d6c6d1-064e-4fdd-a40e-3ecbfcb7ebd0", 0xd6d6c6d1, 0x064e, 0x4fdd, 0xa4, 0x0e, 0x3e, 0xcb, 0xfc, 0xb7, 0xeb, 0xd0)
DEFINE_CODECAPI_GUID(AVDecDDMatrixDecodingMode, "ddc811a5-04ed-4bf3-a0ca-d00449f9355f", 0xddc811a5, 0x04ed, 0x4bf3, 0xa0, 0xca, 0xd0, 0x04, 0x49, 0xf9, 0x35, 0x5f)
DEFINE_CODECAPI_GUID(AVDecDDDynamicRangeScaleHigh, "50196c21-1f33-4af5-b296-11426d6c8789", 0x50196c21, 0x1f33, 0x4af5, 0xb2, 0x96, 0x11, 0x42, 0x6d, 0x6c, 0x87, 0x89)
DEFINE_CODECAPI_GUID(AVDecDDDynamicRangeScaleLow, "044e62e4-11a5-42d5-a3b2-3bb2c7c2d7cf", 0x044e62e4, 0x11a5, 0x42d5, 0xa3, 0xb2, 0x3b, 0xb2, 0xc7, 0xc2, 0xd7, 0xcf)
DEFINE_CODECAPI_GUID(AVDecDDStereoDownMixMode, "6ce4122c-3ee9-4182-b4ae-c10fc088649d", 0x6ce4122c, 0x3ee9, 0x4182, 0xb4, 0xae, 0xc1, 0x0f, 0xc0, 0x88, 0x64, 0x9d)
DEFINE_CODECAPI_GUID(AVDSPLoudnessEqualization, "8afd1a15-1812-4cbf-9319-433a5b2a3b27", 0x8afd1a15, 0x1812, 0x4cbf, 0x93, 0x19, 0x43, 0x3a, 0x5b, 0x2a, 0x3b, 0x27)
DEFINE_CODECAPI_GUID(AVDSPSpeakerFill, "5612bca1-56da-4582-8da1-ca8090f92768", 0x5612bca1, 0x56da, 0x4582, 0x8d, 0xa1, 0xca, 0x80, 0x90, 0xf9, 0x27, 0x68)
DEFINE_CODECAPI_GUID(AVPriorityControl, "54ba3dc8-bdde-4329-b187-2018bc5c2ba1", 0x54ba3dc8, 0xbdde, 0x4329, 0xb1, 0x87, 0x20, 0x18, 0xbc, 0x5c, 0x2b, 0xa1)
DEFINE_CODECAPI_GUID(AVRealtimeControl, "6f440632-c4ad-4bf7-9e52-456942b454b0", 0x6f440632, 0xc4ad, 0x4bf7, 0x9e, 0x52, 0x45, 0x69, 0x42, 0xb4, 0x54, 0xb0)
DEFINE_CODECAPI_GUID(AVEncNoInputCopy, "d2b46a2a-e8ee-4ec5-869e-449b6c62c81a", 0xd2b46a2a, 0xe8ee, 0x4ec5, 0x86, 0x9e, 0x44, 0x9b, 0x6c, 0x62, 0xc8, 0x1a)
DEFINE_CODECAPI_GUID(AVEncChromaEncodeMode, "8a47ab5a-4798-4c93-b5a5-554f9a3b9f50", 0x8a47ab5a, 0x4798, 0x4c93, 0xb5, 0xa5, 0x55, 0x4f, 0x9a, 0x3b, 0x9f, 0x50)

#ifndef UUID_GEN

#define CODECAPI_AVDecVideoThumbnailGenerationMode  DEFINE_CODECAPI_GUIDNAMED(AVDecVideoThumbnailGenerationMode)
#define CODECAPI_AVDecVideoDropPicWithMissingRef    DEFINE_CODECAPI_GUIDNAMED(AVDecVideoDropPicWithMissingRef)
#define CODECAPI_AVDecVideoSoftwareDeinterlaceMode  DEFINE_CODECAPI_GUIDNAMED(AVDecVideoSoftwareDeinterlaceMode)
#define CODECAPI_AVDecVideoFastDecodeMode           DEFINE_CODECAPI_GUIDNAMED(AVDecVideoFastDecodeMode)
#define CODECAPI_AVLowLatencyMode                   DEFINE_CODECAPI_GUIDNAMED(AVLowLatencyMode)
#define CODECAPI_AVDecVideoH264ErrorConcealment     DEFINE_CODECAPI_GUIDNAMED(AVDecVideoH264ErrorConcealment)
#define CODECAPI_AVDecVideoMPEG2ErrorConcealment    DEFINE_CODECAPI_GUIDNAMED(AVDecVideoMPEG2ErrorConcealment)
#define CODECAPI_AVDecVideoCodecType                DEFINE_CODECAPI_GUIDNAMED(AVDecVideoCodecType)
#define CODECAPI_AVDecVideoDXVAMode                 DEFINE_CODECAPI_GUIDNAMED(AVDecVideoDXVAMode)
#define CODECAPI_AVDecVideoDXVABusEncryption        DEFINE_CODECAPI_GUIDNAMED(AVDecVideoDXVABusEncryption)
#define CODECAPI_AVDecVideoSWPowerLevel             DEFINE_CODECAPI_GUIDNAMED(AVDecVideoSWPowerLevel)
#define CODECAPI_AVDecVideoMaxCodedWidth            DEFINE_CODECAPI_GUIDNAMED(AVDecVideoMaxCodedWidth)
#define CODECAPI_AVDecVideoMaxCodedHeight           DEFINE_CODECAPI_GUIDNAMED(AVDecVideoMaxCodedHeight)
#define CODECAPI_AVDecNumWorkerThreads              DEFINE_CODECAPI_GUIDNAMED(AVDecNumWorkerThreads)
#define CODECAPI_AVDecSoftwareDynamicFormatChange   DEFINE_CODECAPI_GUIDNAMED(AVDecSoftwareDynamicFormatChange)
#define CODECAPI_AVDecDisableVideoPostProcessing    DEFINE_CODECAPI_GUIDNAMED(AVDecDisableVideoPostProcessing)
#define CODECAPI_AVEncCommonMeanBitRate             DEFINE_CODECAPI_GUIDNAMED(AVEncCommonMeanBitRate)
#define CODECAPI_AVEncCommonQuality                 DEFINE_CODECAPI_GUIDNAMED(AVEncCommonQuality)
#define CODECAPI_AVEncCommonRateControlMode         DEFINE_CODECAPI_GUIDNAMED(AVEncCommonRateControlMode)
#define CODECAPI_AVEncVideoForceKeyFrame            DEFINE_CODECAPI_GUIDNAMED(AVEncVideoForceKeyFrame)
#define CODECAPI_AVEncMPVDefaultBPictureCount       DEFINE_CODECAPI_GUIDNAMED(AVEncMPVDefaultBPictureCount)
#define CODECAPI_AVEncMPVDefaultBPictureCount       DEFINE_CODECAPI_GUIDNAMED(AVEncMPVDefaultBPictureCount)
#define CODECAPI_AVEncH264CABACEnable               DEFINE_CODECAPI_GUIDNAMED(AVEncH264CABACEnable)

#endif

#endif /* WINAPI_PARTITION_APP */

#endif /*_INC_CODECAPI*/
