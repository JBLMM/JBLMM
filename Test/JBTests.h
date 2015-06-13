#pragma once

#include <ql/math/array.hpp>
#include <string>

#include <LMM/LmmModel/LmmSwaptionMarketData.h>
#include <LMM/calibration/LmmCalibrationConfig.h>
#include <LMM/LmmModel/GMatrixMapping.h>
#include <LMM/LmmModel/Shifted_HGVolatilityFunction.h>



//test JB
void vanillaSwapComparaisonExemple();
void Test_GeneticTargetSwapOneTrajectory();
void Test_McGeneticSwapLMMPricer();
void Test_McGeneticTargetSwapLMMPricing();

void JB_test_LmmCalibrationMarketData();

typedef std::pair<Shifted_HGVolatilityFunction_PTR, GMatrixMapping_PTR>  GMatrix_Vol_gMapping;

LmmSwaptionMarketData_PTR JB_get_LmmSwaptionMarketData(const LmmCalibrationConfig& config, const std::string& input_file);
LMMTenorStructure_PTR JB_create___LMMTenorStructure_PTR(const size_t nbyear);
Correlation_PTR JB_create_InitCorrelation(const LmmCalibrationConfig& config);
Shifted_HGVolatilityFunction_PTR JB_marketData_LMM_ABCD_calibration(const LmmCalibrationConfig& config, LmmSwaptionMarketData_PTR pLmmSwaptionMarketData);
Correlation_PTR JB_marketData_LMM_Correlation_calibration(const LmmCalibrationConfig& config, LmmSwaptionMarketData_PTR pLmmSwaptionMarketData , const QuantLib::Array& found_abcd);
GMatrixMapping_PTR JB_marketData_LMM_CascadeExact_calibration( const LmmCalibrationConfig& config
														   , LmmSwaptionMarketData_PTR pLmmSwaptionMarketData 
														   , const QuantLib::Array& abcd_param 
														   , Correlation_PTR found_correlation_ptr 
														   );
GMatrix_Vol_gMapping JB_marketData_LMM_Global_gCalibration( const LmmCalibrationConfig& config
										, LmmSwaptionMarketData_PTR pLmmSwaptionMarketData 
										, Shifted_HGVolatilityFunction_PTR abcd_param 
										, Correlation_PTR found_correlation_ptr  
										, GMatrixMapping_PTR init_gMapping 
										);
void JB_marketData_LMM_Local_gCalibration( const LmmCalibrationConfig& config
									   , LmmSwaptionMarketData_PTR pLmmSwaptionMarketData 
									   , const QuantLib::Array& abcd_param 
									   , Correlation_PTR found_correlation_ptr  
									   , GMatrixMapping_PTR init_gMapping 
									   );

Shifted_HGVolatilityFunction_PTR		JB_marketData_LMM_shift_Calibration(	const LmmCalibrationConfig& config
																				, LmmSwaptionMarketData_PTR pLmmSwaptionMarketData 
																				, Shifted_HGVolatilityFunction_PTR param_h_g
																			);


