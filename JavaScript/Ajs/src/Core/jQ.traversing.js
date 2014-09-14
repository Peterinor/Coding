(function($){

var runtil = /Until$/,
    rparentsprev = /^(?:parents|prev(?:Until|All))/,
    isSimple = /^.[^:#\[\.,]*$/,
    rneedsContext = $.expr.match.needsContext,
    // methods guaranteed to produce a unique set when starting from a unique set
    guaranteedUnique = {
        children: true,
        contents: true,
        next: true,
        prev: true
    };

$.implement({
    find: function( selector ) {
        var i, ret, self;

        if ( typeof selector !== "string" ) {
            self = this;
            return this.pushStack( $( selector ).filter(function() {
                for ( i = 0; i < self.length; i++ ) {
                    if ( $.contains( self[ i ], this ) ) {
                        return true;
                    }
                }
            }) );
        }

        ret = [];
        for ( i = 0; i < this.length; i++ ) {
            $.find( selector, this[ i ], ret );
        }

        // Needed because $( selector, context ) becomes $( context ).find( selector )
        ret = this.pushStack( $.unique( ret ) );
        ret.selector = ( this.selector ? this.selector + " " : "" ) + selector;
        return ret;
    },

    has: function( target ) {
        var i,
            targets = $( target, this ),
            len = targets.length;

        return this.filter(function() {
            for ( i = 0; i < len; i++ ) {
                if ( $.contains( this, targets[i] ) ) {
                    return true;
                }
            }
        });
    },

    not: function( selector ) {
        return this.pushStack( winnow(this, selector, false) );
    },

    filter: function( selector ) {
        return this.pushStack( winnow(this, selector, true) );
    },

    is: function( selector ) {
        return !!selector && (
            typeof selector === "string" ?
                // If this is a positional/relative selector, check membership in the returned set
                // so $("p:first").is("p:last") won't return true for a doc with two "p".
                rneedsContext.test( selector ) ?
                    $( selector, this.context ).index( this[0] ) >= 0 :
                    $.filter( selector, this ).length > 0 :
                this.filter( selector ).length > 0 );
    },

    closest: function( selectors, context ) {
        var cur,
            i = 0,
            l = this.length,
            ret = [],
            pos = rneedsContext.test( selectors ) || typeof selectors !== "string" ?
                $( selectors, context || this.context ) :
                0;

        for ( ; i < l; i++ ) {
            cur = this[i];

            while ( cur && cur.ownerDocument && cur !== context && cur.nodeType !== 11 ) {
                if ( pos ? pos.index(cur) > -1 : $.find.matchesSelector(cur, selectors) ) {
                    ret.push( cur );
                    break;
                }
                cur = cur.parentNode;
            }
        }

        return this.pushStack( ret.length > 1 ? $.unique( ret ) : ret );
    },

    // Determine the position of an element within
    // the matched set of elements
    index: function( elem ) {

        // No argument, return index in parent
        if ( !elem ) {
            return ( this[0] && this[0].parentNode ) ? this.first().prevAll().length : -1;
        }

        // index in selector
        if ( typeof elem === "string" ) {
            return $.inArray( this[0], $( elem ) );
        }

        // Locate the position of the desired element
        return $.inArray(
            // If it receives a $ object, the first element is used
            elem.$ ? elem[0] : elem, this );
    },

    add: function( selector, context ) {
        var set = typeof selector === "string" ?
                $( selector, context ) :
                $.makeArray( selector && selector.nodeType ? [ selector ] : selector ),
            all = $.merge( this.get(), set );

        return this.pushStack( $.unique(all) );
    },

    addBack: function( selector ) {
        return this.add( selector == null ?
            this.prevObject : this.prevObject.filter(selector)
        );
    }
});

$.fn.andSelf = $.fn.addBack;

function sibling( cur, dir ) {
    do {
        cur = cur[ dir ];
    } while ( cur && cur.nodeType !== 1 );

    return cur;
}

$.each({
    parent: function( elem ) {
        var parent = elem.parentNode;
        return parent && parent.nodeType !== 11 ? parent : null;
    },
    parents: function( elem ) {
        return $.dir( elem, "parentNode" );
    },
    parentsUntil: function( elem, i, until ) {
        return $.dir( elem, "parentNode", until );
    },
    next: function( elem ) {
        return sibling( elem, "nextSibling" );
    },
    prev: function( elem ) {
        return sibling( elem, "previousSibling" );
    },
    nextAll: function( elem ) {
        return $.dir( elem, "nextSibling" );
    },
    prevAll: function( elem ) {
        return $.dir( elem, "previousSibling" );
    },
    nextUntil: function( elem, i, until ) {
        return $.dir( elem, "nextSibling", until );
    },
    prevUntil: function( elem, i, until ) {
        return $.dir( elem, "previousSibling", until );
    },
    siblings: function( elem ) {
        return $.sibling( ( elem.parentNode || {} ).firstChild, elem );
    },
    children: function( elem ) {
        return $.sibling( elem.firstChild );
    },
    contents: function( elem ) {
        return $.nodeName( elem, "iframe" ) ?
            elem.contentDocument || elem.contentWindow.document :
            $.merge( [], elem.childNodes );
    }
}, function( name, fn ) {
	$.implement(name, function( until, selector ) {
        var ret = $.map( this, fn, until );

        if ( !runtil.test( name ) ) {
            selector = until;
        }

        if ( selector && typeof selector === "string" ) {
            ret = $.filter( selector, ret );
        }

        ret = this.length > 1 && !guaranteedUnique[ name ] ? $.unique( ret ) : ret;

        if ( this.length > 1 && rparentsprev.test( name ) ) {
            ret = ret.reverse();
        }

        return this.pushStack( ret );
    })
});

$.extend({
    filter: function( expr, elems, not ) {
        if ( not ) {
            expr = ":not(" + expr + ")";
        }

        return elems.length === 1 ?
            $.find.matchesSelector(elems[0], expr) ? [ elems[0] ] : [] :
            $.find.matches(expr, elems);
    },

    dir: function( elem, dir, until ) {
        var matched = [],
            cur = elem[ dir ];

        while ( cur && cur.nodeType !== 9 && (until === undefined || cur.nodeType !== 1 || !$( cur ).is( until )) ) {
            if ( cur.nodeType === 1 ) {
                matched.push( cur );
            }
            cur = cur[dir];
        }
        return matched;
    },

    sibling: function( n, elem ) {
        var r = [];

        for ( ; n; n = n.nextSibling ) {
            if ( n.nodeType === 1 && n !== elem ) {
                r.push( n );
            }
        }

        return r;
    }
});

// Implement the identical functionality for filter and not
function winnow( elements, qualifier, keep ) {

    // Can't pass null or undefined to indexOf in Firefox 4
    // Set to 0 to skip string check
    qualifier = qualifier || 0;

    if ( $.isFunction( qualifier ) ) {
        return $.grep(elements, function( elem, i ) {
            var retVal = !!qualifier.call( elem, i, elem );
            return retVal === keep;
        });

    } else if ( qualifier.nodeType ) {
        return $.grep(elements, function( elem ) {
            return ( elem === qualifier ) === keep;
        });

    } else if ( typeof qualifier === "string" ) {
        var filtered = $.grep(elements, function( elem ) {
            return elem.nodeType === 1;
        });

        if ( isSimple.test( qualifier ) ) {
            return $.filter(qualifier, filtered, !keep);
        } else {
            qualifier = $.filter( qualifier, filtered );
        }
    }

    return $.grep(elements, function( elem ) {
        return ( $.inArray( elem, qualifier ) >= 0 ) === keep;
    });
}

})(Ajs.$);