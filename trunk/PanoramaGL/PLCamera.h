/*
 * PanoramaGL library
 * Version 0.1
 * Copyright (c) 2010 Javier Baez <javbaezga@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import "PLRenderableElementBase.h"

@interface PLCamera : PLRenderableElementBase 
{
	/**member variables*/
@private
	BOOL isFovEnabled;
	float fov, fovFactor, fovSensitivity;
	PLRange fovRange;
	NSUInteger minDistanceToEnableFov;
	PLRotation initialLookAt;
}

/**properties*/

@property(nonatomic) BOOL isFovEnabled;
@property(nonatomic) float fov, fovSensitivity;
@property(nonatomic, readonly) float fovFactor;
@property(nonatomic, readonly, getter=getFOVFactorCorrected) float fovFactorCorrected;
@property(nonatomic) PLRange fovRange;
@property(nonatomic) NSUInteger minDistanceToEnableFov;
@property(nonatomic) PLRotation initialLookAt;
@property(nonatomic, readonly, getter=getAbsoluteRotation) PLRotation absoluteRotation;

/**init methods*/

+(id)camera;

/**camera methods*/

-(void)addFovWithDistance:(float)distance;
-(void)addFovWithStartPoint:(CGPoint)startPoint endPoint:(CGPoint)endPoint sign:(int)sign;

-(float)getFOVFactorCorrected;

-(void)setInitialLookAtWithPitch:(float)pitch yaw:(float)yaw;
-(void)lookAtWithPitch:(float)pitch yaw:(float)yaw;
-(PLRotation)getAbsoluteRotation;

-(void)cloneCameraProperties:(PLCamera *)value;

@end