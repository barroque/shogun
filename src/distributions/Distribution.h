#ifndef _DISTRIBUTION_H___
#define _DISTRIBUTION_H___

#include "features/Features.h"

#include <math.h>

class CDistribution
{
	public:
		CDistribution();
		virtual ~CDistribution();

		virtual bool train()=0;

		/// get number of parameters in model
		virtual INT get_num_model_parameters()=0;

		/// get number of parameters in model that are relevant,
		/// i.e. > ALMOST_NEG_INFTY
		virtual INT get_num_relevant_model_parameters();

		//get model parameter (logarithmic)
		virtual REAL get_log_model_parameter(INT param_num)=0;

		//get derivative of likelihood function (logarithmic)
		virtual REAL get_log_derivative(INT param_num, INT num_example)=0;
		
		/// compute log likelihood for example
		virtual REAL get_log_likelihood_example(INT num_example)=0;

		/// compute log likelihood for whole sample
		virtual REAL get_log_likelihood_sample();

		/// compute log likelihood for each example
		virtual REAL* get_log_likelihood_all_examples();

		//get model parameter
		virtual inline REAL get_model_parameter(INT param_num)
		{
			return exp(get_log_model_parameter(param_num));
		}

		//get derivative of likelihood function
		virtual inline REAL get_derivative(INT param_num, INT num_example)
		{
			return exp(get_log_derivative(param_num, num_example));
		}

		/// compute likelihood for example
		virtual inline REAL get_likelihood_example(INT num_example)
		{
			return exp(get_log_likelihood_example(num_example));
		}

		/// set and get feature vectors
		virtual inline void set_features(CFeatures* f) { features=f; }
		virtual inline CFeatures* get_features() { return features; }

		/// set and get pseudo count
		virtual inline void set_pseudo_count(REAL pseudo) { pseudo_count=pseudo; }
		virtual inline REAL get_pseudo_count() { return pseudo_count; }

	protected:
		CFeatures* features;
		REAL pseudo_count;
};
#endif

