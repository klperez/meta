/**
 * @file jelinek_mercer.h
 *
 * All files in META are released under the MIT license. For more details,
 * consult the file LICENSE in the root of the project.
 *
 * @author Sean Massung
 */

#ifndef _JELINEK_MERCER_H_
#define _JELINEK_MERCER_H_

#include "index/ranker/lm_ranker.h"

namespace meta
{
namespace index
{

/**
 * Implements the Jelinek-Mercer smoothed ranking model. This smoothing method
 * can be viewed as a linear interpolation between the query term probablity
 * and the collection term probability. The model parameter lambda is the
 * weighting of this interpolation.
 */
class jelinek_mercer : public language_model_ranker
{
  public:
    /**
     * @param lambda
     */
    jelinek_mercer(double lambda = 0.7);

    /**
     * Calculates the smoothed probability of a term.
     * @param sd
     */
    double smoothed_prob(const score_data& sd) const override;

    /**
     * A document-dependent constant.
     * @param sd
     */
    double doc_constant(const score_data& sd) const override;

  private:
    /** the JM parameter*/
    const double _lambda;
};
}
}

#endif