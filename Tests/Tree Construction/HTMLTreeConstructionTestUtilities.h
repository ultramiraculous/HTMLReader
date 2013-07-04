//
//  HTMLTreeConstructionTestUtilities.h
//  HTMLReader
//
//  Created by Nolan Waite on 2013-06-26.
//  Copyright (c) 2013 Nolan Waite. All rights reserved.
//

#import "HTMLDocument.h"
#import "HTMLParser.h"

extern NSArray * ReifiedTreeForTestDocument(NSString *document);

#define HTMLAssertParserState(parser, numErrors, fixtureNodes, description, ...) \
do { \
    @try { \
        id rootNodes = [[(parser) document] childNodes]; \
        if (![rootNodes isEqual:(fixtureNodes)]) { \
            [self failWithException:([NSException failureInEqualityBetweenObject:rootNodes \
                                                                       andObject:(fixtureNodes) \
                                                                          inFile:[NSString stringWithUTF8String:__FILE__] \
                                                                          atLine:__LINE__ \
                                                                 withDescription:@"%@", STComposeString(description, ##__VA_ARGS__)])]; \
        } \
        else if ([[(parser) errors] count] != numErrors) { \
            [self failWithException:([NSException failureInEqualityBetweenValue:@([[(parser) errors] count]) \
                                                                       andValue:@(numErrors) \
                                                                   withAccuracy:nil \
                                                                         inFile:[NSString stringWithUTF8String:__FILE__] \
                                                                         atLine:__LINE__ \
                                                                withDescription:@"%@", STComposeString(description, ##__VA_ARGS__)])]; \
        } \
    } \
    @catch (id anException) { \
        [self failWithException:([NSException failureInRaise:@"parser state" \
                                                   exception:anException \
                                                      inFile:[NSString stringWithUTF8String:__FILE__] \
                                                      atLine:__LINE__ \
                                             withDescription:@"%@", STComposeString(description, ##__VA_ARGS__)])]; \
    } \
} while(0)
